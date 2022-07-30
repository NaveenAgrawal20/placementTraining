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
        int n, flag = -1, x = 0, y = 0, i;
        string direc;
        cin >> n;
        cin >> direc;
        for (i = 0; i < n; i++)
        {
            if (flag == 0 || i == 0)
            {
                if (direc[i] == 'L')
                {
                    x--;
                    flag = 1;
                }
                else if (direc[i] == 'R')
                {
                    x++;
                    flag = 1;
                }
            }
            if (flag == 1 || i == 0)
            {
                if (direc[i] == 'U')
                {
                    y++;
                    flag = 0;
                }
                else if (direc[i] == 'D')
                {
                    y--;
                    flag = 0;
                }
            }
        }
        cout << x << " " << y << "\n";
    }

    return 0;
}
/*
4
5
LLLUR
7
LLLRUUD
8
LRULLUDU
10
UUDRLDULUR
*/