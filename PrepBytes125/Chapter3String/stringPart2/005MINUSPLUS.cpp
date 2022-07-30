#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int i;

        string s, t, temp;
        cin >> s;
        cin >> t;
        bool flag = true;
        int sn = s.length(), j = 0;
        if (sn < t.length())
            flag = false;
        else
        {
            for (i = 0; i < sn; i++)
            {
                if (t[j] == s[i])
                {
                    j++;
                }
                else if (t[j] == '+' && s[i] == '-' && s[i + 1] == '-')
                {
                    i++;
                    j++;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

/*
5
-+--+
-+++
--------
-+--+-
--
---
+++
+++
--+-+-+--++-
++-+-++++-
*/
