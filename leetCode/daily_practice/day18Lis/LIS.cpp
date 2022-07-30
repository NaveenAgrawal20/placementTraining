#include<bits/stdc++.h>
using namespace std;

template <typename T>
void _getVector(vector<T>& v)
{
	string s;
	getline(cin, s);
	string str = string(s.begin() + 1, s.end() - 1);
	replace(str.begin(), str.end(), ',', ' ');
	// cout<<str;

	stringstream ss(str);
	T x;
	while ( ss >> x)
	{
		v.push_back(x);
	}
}`


class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
    	int n = nums.size();
    	int dp[n];
    	int ans = 0;
    	for(int i = 0;i<n;++i)
    	{
    		int maxL = 0;
    		for(int j = i-1;j>=0;--j)
    		{
    			if(nums[j] < nums[i])
    				maxL = max(maxL,dp[j]);
    		}
    		dp[i] = maxL+1;

    		ans = max(ans,dp[i]);
    	}
    	return ans;
	}
};


int main()
{
	int t = 3;
	while (t--)
	{
		vector<int> v;
		_getVector(v);
		Solution s;
	}

	return 0;
}