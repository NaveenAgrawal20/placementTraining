#include <bits/stdc++.h>
using namespace std;
int dp[150][150];

int util(int a[], int i, int j)
{
    // if()

    if (j < i)
        return 0;
    if (i + 1 == j)
    {
        //  cout<<"a"<<i<<" "<<j<<endl;
        return max(a[i], a[j]);
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = max(a[i] + min(util(a, i + 1, j - 1), util(a, i + 2, j)), a[j] + min(util(a, i + 1, j - 1), util(a, i, j - 2)));
    // cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
    return dp[i][j];
}
int ops(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    return util(a, 0, n - 1);
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << ops(a, n) << endl;
    }
    return 0;
}