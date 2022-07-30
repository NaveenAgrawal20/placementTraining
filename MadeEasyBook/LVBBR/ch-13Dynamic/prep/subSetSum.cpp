#include <iostream>
using namespace std;

// bool dp[101][101];

// bool solve(int sum, int n, int *set)
// {
//     if (sum == 0)
//         return true;
//     if (n == 0)
//         return false;
//     if (set[n - 1] <= sum)
//         dp[n][sum] = (solve(sum - set[n - 1], n - 1, set) || solve(sum, n - 1, set));
//     else
//         dp[n][sum] = solve(sum, n - 1, set);
//     return dp[n][sum];
// }

bool solveTab(int sum, int n, int *set)
{
    // First Row = FALSE
    // First column = True
    bool dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
     for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (set[i-1] <= j)
                dp[i][j] = dp[i-1][j - set[i-1]]  || dp[i - 1][j];
            else if (set[i-1] > j)
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int t = 3;
    cin >> t;
    while (t--)
    {
        int sum;
        cin >> sum;
        // int set[] = {2,4,8,9,11,3,-1,5,16,120,14125,110,1,4540,523,244,1245};
        int set[] = {3, 4, 8, 9, 11};
        cout << "Sum EXISTS = " << (solveTab(sum, sizeof(set) / sizeof(set[0]), set) ? "Yes" : "NO") << '\n';
    }
    return 0;
}