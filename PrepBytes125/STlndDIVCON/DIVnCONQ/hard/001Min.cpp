#include <iostream>
#include <string>
using namespace std;

bool check(int p, string s)
{
    int i, j, siz = s.size();
    char c;
    for (i = 0; i <= 25; i++)
    {
        c = 'a' + i;
        // 1. check for c's last position in p length
        int last = -1;
        for (j = 0; j < p; j++)
        {
            if (s[j] == c)
                last = j;
        }
        // if c not present
        if (last == -1)
            continue;

        // checking if c is in [p,size] string // a valid char
        bool present = true;
        for (j = p; j < siz; j++)
        {
            if (s[j] == c)
            {
                last = j;
            }
            // for c to be in length P string it last
            if (j - last >= p)
            {
                present = false;
                break;
            }
        }
        if (present)
            return present;
    }
    return false;
}

int bSearch(string s, int low, int high)
{
    int mid = (low + high) / 2;
    if (low > high)
        return low;
    if (check(mid, s))
    {
        return bSearch(s, low, mid - 1);
    }
    else
        return bSearch(s, mid + 1, high);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        cout << bSearch(s, 1, s.size()) << endl;
    }
    return 0;
}