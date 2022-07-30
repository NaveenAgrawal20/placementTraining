#include <iostream>
using namespace std;

int main()
{
    int m, n, i, j, k;
    cin >> m >> n >> k;
    int a[m][n];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] * k<<" ";
        cout << "\n";
    }

    return 0;
}
/*
2 2 5
1 2
3 4
*/