#include <iostream>
#include <cstring>
using namespace std;

// bool dp[10][10][10];
// bool dp[n + 1][n][n];
bool isScrambled_DP(string s1, string s2)
{
    int n = s1.length();
    if (n != s2.length())
        return false;
    bool dp[n + 1][n][n];
    memset(dp,false,sizeof(dp));
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            for (int j = 0; j <= n - len; j++)
            {

                if (len == 1)
                    dp[len][i][j] = (s1[i] == s2[j]);
                else
                {
                    for (int k = 1; k <= len - 1 && !dp[len][i][j]; k++)
                    {
                        dp[len][i][j] = (dp[k][i][j] && dp[len - k][i + k][j + k]) 
                                        || (dp[k][i][j+len-k] && dp[len - k][i + k][j]);
                    }
                }
            }
        }
    }
    return dp[n][0][0];
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << (isScrambled_DP(a, b) ? 'T' : 'F') << '\n';
    return 0;
}
/*
coder
ocder
T
great
rgeat
T
abcde
caebd
F
*/