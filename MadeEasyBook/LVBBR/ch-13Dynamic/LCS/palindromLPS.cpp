#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int solve(string a)
{
    int n = a.length();
    string b = a;
    reverse(b.begin(), b.end());

    // LCS logic
    int dp[n + 1][n + 1];
    memset(dp,0,sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        for (int j = n; j >= 0; j--)
        {
            // First row and first column
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i-1][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j:dp[i])
            cout << j << ' ';
        cout << '\n';
    }
    int lcsLen = dp[n][n];
    return (lcsLen);
}

string longestPalindrome(string a) {
    int n = a.size();
    if (n == 1)
        return a;

    int u, v, result = 0;
    string b = a;
    reverse(b.begin(), b.end());
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; ++i)
        dp[i][0] = dp[0][i] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (result < dp[i][j]) {
                    result = dp[i][j];
                    u = i;
                    v = j;
                }
            } else
                dp[i][j] = 0;
        }
    }
//    for (int i = 0; i <= n; ++i)
//    {
//        for (int j:dp[i])
//            cout << j << ' ';
//        cout << '\n';
//    }
//    cout<<"U and V"<<u<<' '<<v<<'\n';
    // printing LPS
    string ans;
    int i = u,j = v;
    while(i > 0 && j > 0)
    {
        if(a[i-1] == b[j-1])
        {
            ans += b[j-1];
            i--;j--;
        }
        else if(dp[i][j-1] > dp[i-1][j])
            j--;
        else
            i--;
    }
    return ans;
}

int main()
{
    int t = 8;
    while (t--)
    {
        string str;
        cin >> str;
        cout << solve(str) << '\n';
    }

    return 0;
}
/*
abgeba
aacabdkacaa
abba
abeba
*/