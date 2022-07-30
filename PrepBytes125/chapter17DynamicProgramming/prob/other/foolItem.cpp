#include <iostream>
#include <climits>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max(a, max(b, c)); }
int maxProd(int n)
{
    if (n == 0 || n == 1)
        return 0;

    int max_val = 0;
    for (int i = 1; i < n; i++)
        max_val = max(max_val, i * (n - i), maxProd(n - i) * i);

    return max_val;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int dp[101];
    dp[0] = 0,dp[1] = 0, dp[2] = 1, dp[3] = 2, dp[4] = 4,  dp[5] = 6, dp[6] = 9;
    for (int i = 7; i < 101; i++)
    {
        long long int mx = -1;
        for (int j = 1; j <= i; j++)
        {
            mx = max(mx, dp[j] * (i - j));
        }
        dp[i] = mx;
    }
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
/*
10
1
2
3
4
5
6
7
8
9
10
*/