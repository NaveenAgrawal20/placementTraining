#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& arr) {
	int n = arr.size();
	int dp[n];
	dp[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int mx = 0;
	for (int i = 0; i < n; ++i)
		mx = max(mx, dp[i]);
	return mx;
}

int maxSumIS(vector<int> arr, int n)
{
	int dp[n];
	for (int i = 0; i < n; ++i)
		dp[i] = arr[i];
	int mx = dp[0];
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + arr[i]);
			mx = max(mx, dp[i]);
		}
	}
	return mx;
}

int lisRec(vector<int> &arr, int n, int &maxRef)
{
	if (n == 1)
		return 1;

	int res, maxRes;
	for (int i = 1; i < n; ++i)
	{
		res = lisRec(arr, i, maxRef);
		if (arr[i - 1] < arr[n - 1])
			maxRes = res + 1;
	}
	maxRef = max(maxRef, maxRes);
	return maxRes;
}


int main()
{
	vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	// vector<int> arr = {3, 10, 2, 1, 20};

	cout << lisRec(arr, arr.size(), INT_MIN);

	return 0;
}