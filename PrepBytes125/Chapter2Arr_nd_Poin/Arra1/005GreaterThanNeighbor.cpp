#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, i, idx = -1;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = 0; i < n; i++)
        {
            if (i == 0 && a[i] > a[i + 1]){
                idx  = i;
                cout << idx << " ";
            }
            else if (i == n - 1 && a[i] > a[i - 1]){
                idx  = i;
                cout << idx << " ";
            }
            else if (a[i] > a[i + 1] && a[i] > a[i - 1]){
                idx  = i;
                cout << idx << " ";
            }
        }
        if (idx == -1 )
            cout << -1;
        cout << "\n";
    }

    return 0;
}
/*
2
5
4 3 5 2 1
7
7 2 8 4 3 9 1
/*
corner case
6
3 5 4 2 1 6
*/