// Count no of subsets with given difference (DP)
#include <iostream>
using namespace std;

// utility for sum of arr
int sum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}
int solve(int *set, int n, int D)
{
    int maxSum = sum(set, n);
    int sumToFound = (D + maxSum) / 2;
    int dp[n + 1][sumToFound + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= sumToFound; ++j)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sumToFound; j++)
        {
            if (set[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - set[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sumToFound; j++)
            cout << dp[i][j] << '\t';
        cout << '\n';
    }

    return dp[n][sumToFound];
}

int main()
{
    int arr[4] = {1, 2, 3, 4};
    int diff = 2;
    cout << solve(arr, 4, diff) << '\n';
    return 0;
}
/*
Here, we have to add two more conditions that:
(1): if given diff is odd and total sum of array is even
(2): if given diff is even and total sum of array is odd
In these two conditions, it is not possible to break array in two subsets with given difference.
*/