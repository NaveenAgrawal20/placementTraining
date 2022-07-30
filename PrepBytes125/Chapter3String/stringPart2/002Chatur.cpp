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
        int n, i, opCount = 0;
        string str;
        cin >> str;
        n = str.length();
        for (i = 0; i < n / 2; i++)
        {
            if (str[i] != str[n - 1 - i])
            {
                opCount += abs(str[i]-str[n - 1 - i]);
            }
        }
        cout<<opCount<<"\n";
    }

    return 0;
}
/*
4
abc
abcba
abcd
cba
o/p = 
2
0
4
*/