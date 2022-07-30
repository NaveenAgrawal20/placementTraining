#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"

void solve(int *a, int n)
{
    sort(a, a + n);
    int i, j, n1 = 0, n2, n3, flag = 0;
    for (i = n - 1; i >= n / 2; i--)
    {
        for (j = 0; j < n / 2; j++)
        {
            if (binary_search(a+j+1, a + n, a[i] - a[j]))
            {
                n3 = a[i] - a[j];

                if (a[i] >= n1 && n3 > a[j])
                {
                    flag = 1;
                    n1 = a[i];
                    n2 = a[j];
                    break;
                }
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 0)
        cout << -1 << endl;
    else
        cout << n1 << " " << n2 << " " << n3 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        solve(a, n);
    }
    return 0;
}
/*
3
5
20 40 30 50 70
4
29 15 13 30
4
10 45 35 60
*/