#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

void solve(int *p, int n)
{
    int dp[n][n];
    int s[n][n];
    memset(dp,0,sizeof(dp));
    memset(s,0,sizeof(s));

    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l; i++)
        {
            int j = l - 1 + i;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }
    cout << "\nORDER\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << s[i][j] << ' ';
        cout << endl;
    }
    cout<<"Min mutli is  = "<<dp[1][n-1]<<' ';
}

int main()
{
    // int arr[] = {2,3,5,6,7};
    // int arr[] = {3, 100, 2, 2};
    int arr[] = {5, 4, 6, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n);
    return 0;
}