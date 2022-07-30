#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, i, lidx = -1;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            lidx = a[i] == 1?i:lidx;
        }
        cout<<lidx<<"\n";
    }

    return 0;
}
/*
2
3
0 1 1
6
0 0 0 0 0 0
*/