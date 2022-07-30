#include <iostream>
using namespace std;

int solveUBKnapSack(int *wt,int *val, int n, int W)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= W; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i-1] <= j)
                dp[i][j] = max(dp[i-1][j],dp[i][j-wt[i-1]]+val[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}
int knapSack(int wt[], int val[], int n,int W)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                              K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
// O(n) space complexity

int solveUBKnapSack_1DArr(int *wt,int *val, int n, int W)
{
    int dp[W + 1] = {0};
    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (wt[j] <= i)
                dp[i] = max(dp[i],dp[i-wt[j]]+val[j]);
        }
    }

    return dp[W];
}

int main()
{
    int n;
    cin >> n;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int target;
    cin >> target;
    cout << solveUBKnapSack(wt,val,n, target) << '\n';
    cout << solveUBKnapSack_1DArr(wt,val,n, target) << '\n';
    return 0;
}