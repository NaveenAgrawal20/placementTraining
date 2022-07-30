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
        int i, alpha[26] = {0};
        bool flag = false;
        string str;
        cin >> str;
        int n = str.length();
        for (i = 0; i < n; i++)
            alpha[str[i] - 'a']++;

        for (i = 0; i < 26; i++)
        {
            if (alpha[i] >= 2)
            {
                cout << char(i + 'a') << "=" << alpha[i] << " ";
                flag = true;
            }
        }
        if(!flag)
            cout<<-1;
        cout << "\n";
    }

    return 0;
}
/*
3
prepbytes
java
algorithm
*/