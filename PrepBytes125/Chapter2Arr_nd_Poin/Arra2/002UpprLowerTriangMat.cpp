#include <iostream>
using namespace std;

int main()
{

    int m, n, i, j;
    cin >> m >> n;
    int a[m][n];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];

    // lower
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j > i)
                cout << 0 << " ";
            else
                cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    // upper
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            if (j >= i)
                cout << a[i][j] << " ";
            else
                cout << 0 << " ";
        cout << "\n";
    }
    return 0;
}
/*
4
1 1
1
2 2
1 2
3 4
3 3
1 2 3
4 5 6
7 8 9
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
*/