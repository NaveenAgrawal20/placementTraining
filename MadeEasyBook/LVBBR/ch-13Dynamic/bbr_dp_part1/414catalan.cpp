#include<bits/stdc++.h>
using namespace std;

int getCatalan(int n)
{
	int dp[n+1];
	dp[0] = dp[1] = 1;
	for(int i = 2;i<=n;++i)
	{
		dp[i] = 0;
		for(int j = 0;j<i;++j)
		{
			dp[i] += dp[j]*dp[i-j-1];
		}
	}
	return dp[n];
}

int main()
{
	for (int i = 0; i < 10; i++)
        cout << getCatalan(i) << " ";
    return 0;
}