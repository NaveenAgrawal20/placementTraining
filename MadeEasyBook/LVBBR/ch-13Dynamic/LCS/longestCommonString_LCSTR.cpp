#include <iostream>
#include <cstring>
using namespace std;

int lcsRec(string s1, string s2, int l1, int l2, int len)
{
    if (l1 == 0 || l2 == 0)
        return len;
    if (s1[l1 - 1] == s2[l2 - 1]) // same Str1[idx] == Str2[idx]
        len = lcsRec(s1, s2, l1 - 1, l2 - 1, len+1);
    else
    {
        int t1 = lcsRec(s1, s2, l1 - 1, l2, 0);
        int t2 = lcsRec(s1, s2, l1, l2 - 1, 0);
        return max(len, max(t1, t2));
    }
    return len;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcsRec(s1, s2, s1.length(), s2.length(), 0) << '\n';
    }
    return 0;
}
/*
4
abcdef
xabcef
abdc
abec
aebc
adbc
angur
ngu
*/