#include <iostream>
#include <cstring>
using namespace std;

int dp[100][100];
int lcsRec(string s1, string s2, int l1, int l2)
{
    if (l1 == 0 || l2 == 0)
        return 0;
    if(dp[l1][l2] != 0)
        return dp[l1][l2];

    if (s1[l1 - 1] == s2[l2 - 1]) // same Str1[idx] == Str2[idx]
        dp[l1][l2] =  1 + lcsRec(s1, s2, l1 - 1, l2 - 1);
    else
        dp[l1][l2] =  max(lcsRec(s1, s2, l1 - 1, l2), lcsRec(s1, s2, l1, l2 - 1));
    return dp[l1][l2];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // clear dp on every run
        memset(dp,0,sizeof(dp));
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcsRec(s1, s2, s1.length(), s2.length()) << '\n';
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