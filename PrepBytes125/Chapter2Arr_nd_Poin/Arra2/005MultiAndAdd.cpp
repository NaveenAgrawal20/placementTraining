#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int m, n, i, j;
        cin >> m >> n;
        int a[m][n], b[m][n];

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                cin >> a[i][j];

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                cin >> b[i][j];

        //addition
        int c[m][n];
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                c[i][j] = a[i][j] + b[i][j];

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                cout << c[i][j] << " ";
            cout << "\n";
        }

        // multi
        for (i = 0; i < m; i++) // m of 1st matr
        {
            for (j = 0; j < n; j++) // n of 2nd matr
            {
                c[i][j] = 0;
                c[i][j] = 0;
                for (int k = 0; k < m; k++)  // resultant 
                {
                    c[i][j] += a[i][k] * b[k][j]; 
                }
            }
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                cout << c[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}
/*
1
2 2
1 2
3 4
5 6
7 8
*/