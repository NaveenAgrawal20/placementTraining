#include <iostream>
#include <climits>
using namespace std;

int solve(int *arr, int i, int j, int ans)
{
    if (i == j)
        return 0;

    for (int k = i; k <= j - 1; ++k)
    {
        int tempAns = arr[i - 1] * arr[k] * arr[j] + solve(arr, i, k,ans) + solve(arr, k + 1, j,ans);
        ans = min(tempAns, ans);
    }
    return ans;
}

int solveDP(int *arr,int n)
{
    int dp[n][n];
    for(int i = 0;i<=n;i++)
        dp[i][i] = 0;
    for(int i = 2;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            dp[i][j]
        }
    }
}


int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        int arr[] = {2, 3, 5, 6, 7};
        // int n = sizeof(arr)/sizeof(arr[0]);
        cout << solve(arr, 1, sizeof(arr) / sizeof(arr[0]) - 1, INT_MAX) << '\n';
    }
    return 0;
}