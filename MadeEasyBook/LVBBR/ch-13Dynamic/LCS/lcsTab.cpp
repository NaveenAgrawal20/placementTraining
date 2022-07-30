#include <iostream>
#include <cstring>
using namespace std;

int lcsTabulation(string s1, string s2, int l1, int l2)
{
    int dp[l1 + 1][l2 + 1];
    memset(dp,0,sizeof(dp));
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; ++j)
        {
            // First row and first column
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else if(s1[i-1] != s2[j-1])
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[l1][l2];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcsTabulation(s1, s2, s1.length(), s2.length()) << '\n';
    }
    return 0;
}

/*
2
ABCDGH
AEDFHR
AGGTAB
GXTXAYB
*OUT*
3 (ADH)
4 (GTAB)
*/