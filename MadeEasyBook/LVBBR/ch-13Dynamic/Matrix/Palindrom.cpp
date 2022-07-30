#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int minCut(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n));

    for (int l = 0; l <= n; ++l)
    {
        for (int i = 0, j = l; j < n; ++i, j++)
        {
            if (l == 0)
            {
                dp[i][j] = true;
            }
            else if (l == 1)
                dp[i][j] = (s[i] == s[j]);
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1])
                    dp[i][j] = true;
                else
                {
                    dp[i][j] = false;
                }
            }
        }
    }

    vector<vector<int>> strg(n, vector<int>(n));
    for (int l = 0; l <= n; ++l)
    {
        for (int i = 0, j = l; j < n; ++i, j++)
        {
            if (l == 0)
            {
                strg[i][j] = 0;
            }
            else if (l == 1)
            {
                if (s[i] == s[j])
                    strg[i][j] = 0;
                else
                    strg[i][j] = 1;
            }
            else
            {
                if(dp[i][j])
                    strg[i][j] = 0;
                else{
                    strg[i][j] = INT_MAX;
                    for(int k = i;k<j;++k)
                    {
                        strg[i][j] = min(strg[i][j],strg[i][k]+strg[k+1][j]+1);
                    }
                }
            }
        }
    }
    return strg[0][n-1];
}

int main()
{
    int t = 10;
    while (t--)
    {
        string s;
        cin >> s;
        cout << minCut(s) << '\n';
    }
    return 0;
}