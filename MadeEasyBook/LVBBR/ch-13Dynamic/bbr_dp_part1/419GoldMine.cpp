#include<bits/stdc++.h>
using namespace std;

int getMaxGold(vector<vector<int>>& gold, vector<vector<int>>& dp,
               int row, int col, int n, int m)
{
	if (row < 0 || row == n || col == m)
		return 0;

	if (dp[row][col] != -1)
		return dp[row][col];

	int right =   getMaxGold(gold, dp, row, col + 1, n, m);
	int rightUp = getMaxGold(gold, dp, row - 1, col + 1, n, m);
	int rightDw = getMaxGold(gold, dp, row + 1, col + 1, n, m);

	dp[row][col] = gold[row][col] + max(right,max(rightUp,rightDw));
	return dp[row][col];
}

int getMaximumGold(vector<vector<int>>& gold)
{
	int n = gold.size();
	int m = gold[0].size();

	int maxGold = INT_MIN;

	vector<vector<int>> dp(n, vector<int> (m, -1));
	for (int i = 0; i < n; ++i)
	{
		int goldCollectedPerIthRow = getMaxGold(gold, dp, i, 0, n, m);
		maxGold = max(maxGold, goldCollectedPerIthRow);
	}
	for(int i = 0;i<n;++i)
	{
		for(int j = 0;j<m;++j)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	return maxGold;
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> gold;
		for (int i = 0; i < n; ++i)
		{
			vector<int> col;
			for (int j = 0; j < m; ++j)
			{
				int value;
				cin >> value;
				col.push_back(value);
			}
			gold.push_back(col);
		}
		cout<<getMaximumGold(gold)<<endl;
	}
	return 0;
}
/*
4
5 3
1 0 7
2 0 6
3 4 5
0 3 0
9 0 20
3 3
1 3 3
2 1 4
0 6 4
4 4
1 3 1 5
2 2 4 1
5 0 2 3
0 6 1 2
4 4
10 33 13 15
22 21 04 1
5 0 2 3
0 6 14 2
*/