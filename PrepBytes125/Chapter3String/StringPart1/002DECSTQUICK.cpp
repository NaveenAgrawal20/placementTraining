// #include <bits/stdc++.h>
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
        int i, j;
        int alpha[26] = {0}; // index [0 = a, 25 = z]
        string str;
        cin >> str;
        int n = str.size();
        for (i = 0; i < n; i++)
        {
            alpha[str[i] - 'a']++;
        }
        for (i = 25; i >= 0; i--)
        {
            for (j = 1; j <= alpha[i]; j++)
                cout << char(i + 'a');
        }
        cout<<"\n";
    }

    return 0;
}
/* 
2
prepbytes
algorithm
 */