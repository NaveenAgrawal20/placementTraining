#include <iostream>
using namespace std;
typedef long long ll;

ll dp[11];
ll solve(int n)
{
    dp[0] = dp[1] = 1;
    if(dp[n] != 0)
        return dp[n];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= i; j++)
        {
            dp[i] += solve(j-1) * solve(i - j);
        }
    }
    return dp[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}