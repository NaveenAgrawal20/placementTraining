#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
	int carAssembly(vector<vector<int>> &a, vector<vector<int>> &t,
	                vector<int> &e, vector<int> &x)
	{
		int num_station = a[0].size();
		int line1[num_station], line2[num_station];

		// time for 1st station
		line1[0] = e[0] + a[0][0];
		line2[0] = e[1] + a[1][0];

		for (int i = 1; i < num_station; ++i)
		{
			// arriving and leaving station s[1,i] has two possible cases
			// 1. '/' (from s[2,i-1]) OR   '->' 2. (from s[1,i-1])
			line1[i] = min(line2[i - 1] + t[1][i] + a[0][i], line1[i - 1] + a[0][i]);

			// similarly for s[2,i]
			//1. '/' (from s[1,i-1])  OR   '->' 2. (from s[1,i-1])
			line2[i] = min(line1[i - 1] + t[0][i] + a[1][i], line2[i - 1] + a[1][i]);
		}
		return min(line1[num_station - 1] + x[0], line2[num_station - 1] + x[1]);
	}
};

int main()
{
	Solution s;
	vector<vector<int>> a = {{4, 5, 3, 2},
		{2, 10, 1, 4}
	};

	vector<vector<int>> t = {{0, 7, 4, 5},
		{0, 9, 2, 8}
	};

	vector<int> e = {10, 12}, x = {18, 7};

	cout << s.carAssembly(a, t, e, x);

	return 0;
}
