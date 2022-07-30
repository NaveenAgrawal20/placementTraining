#include <iostream>
#include<cstring>
using namespace std;

int n, k, p;
int dp[51][1501];
int a[50][30];

void solve()
{
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        memcpy(dp[i+1],dp[i],sizeof(dp[0]));
        for (int j = 0, s = 0; j < k; j++)
        {
            cin >> a[i][j];
            s += a[i][j];
            for(int l = 0;l+j+1<=p;l++)
                dp[i+1][l+j+1] = max(dp[i][l]+s,dp[i+1][l+1+j]);
        }
    }
    cout<<dp[n][p]<<'\n';

    for(int  i =0;i<=n;i++)
    {
        for(int j = 0;j<=p;++j)
            cout<<dp[i][j]<<' ';
        cout<<'\n';
    }
}

int main()
{
    cin >> n >> k >> p;

    solve();
    return 0;
}

// 2 4 5
// 10 10 100 30
// 80 50 10 50