#include <iostream>
#include <cstring>
using namespace std;

int getCoinWays(int amt, int *coins, int n)
{

    if (amt == 0 && n >= 1)
        return 1;
    if (amt == 0 || n == 0)
        return 0;

    if (coins[n - 1] <= amt)
        return getCoinWays(amt - coins[n - 1], coins, n) + getCoinWays(amt, coins, n - 1);
    else
        return getCoinWays(amt, coins, n - 1);
}

int getCoin_DP(int amt, int *coins, int n)
{
    int dp[n + 1][amt + 1];
    memset(dp,0,sizeof(dp)); 
    for (int i = 0; i <= amt; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amt; j++)
        {
            if (coins[i-1] <= j)
                dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <=amt; j++)
    //         cout << dp[i][j] << '\t';
    //     cout << '\n';
    // }
    return dp[n][amt];
}

int getCoin_DP_1D(int amt, int *coins, int n)
{
    int dp[amt+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    // loop reversed
    /*
    https://leetcode.com/problems/coin-change-2/discuss/176706/Beginner-Mistake%3A-Why-an-inner-loop-for-coins-doensn't-work-Java-Soln
    */
    for(int i = 0;i<n;i++)
    {
        for(int j = i;j<=amt;j++)
        {
            if(coins[i] <= j)
                dp[j] += dp[j-coins[i]];
        }
    }
    for(int i = 0;i<=amt;i++)
        cout<<dp[i]<<' ';
    cout<<endl;
    return dp[amt];
}
int main()
{
    int amt, n;
    cin >> amt;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; ++i)
        cin >> coins[i];
    // cout << getCoinWays(amt, coins, n) << '\n';
    cout << getCoin_DP(amt, coins, n) << '\n';
    cout << getCoin_DP_1D(amt, coins, n) << '\n';
    return 0;
}
/*
4
3
1 2 3

10
4
2 5 3 6

500

3 5 7 8 9 10 11
*/