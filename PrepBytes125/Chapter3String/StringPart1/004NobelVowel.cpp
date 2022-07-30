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
        bool nobel = true;
        string str;
        cin >> str;
        int n = str.length();
        for (i = 0; i < n ; i++)
        {
            if (str[i] != 'n' && str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
            {
                if (str[i + 1] == '\0' || str[i + 1] != 'a' && str[i + 1] != 'e' && str[i + 1] != 'i' && str[i + 1] != 'o' && str[i + 1] != 'u')
                {
                    nobel = false;
                    break;
                }
            }
        }
        if (nobel)
            cout << "YES"<< "\n";
        else
            cout << "NO"
                 << "\n";
    }

    return 0;
}
/*
6
aeiou
cefduo
sumimasen
ninja
codeforces
coder
*/