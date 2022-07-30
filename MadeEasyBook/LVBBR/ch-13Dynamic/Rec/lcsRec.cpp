#include <iostream>
#include <cstring>
using namespace std;

int lcsRec(string s1, string s2, int l1, int l2)
{
    if (l1 == 0 || l2 == 0)
        return 0;
    if (s1[l1 - 1] == s2[l2 - 1]) // same Str1[idx] == Str2[idx]
        return 1 + lcsRec(s1, s2, l1 - 1, l2 - 1);
    // else
    return max(lcsRec(s1, s2, l1 - 1, l2), lcsRec(s1, s2, l1, l2 - 1));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
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