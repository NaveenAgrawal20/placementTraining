#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"
/*https://www.codechef.com/problems/SHUFFLE*/

void solve(int *a, int n, int k)
{
    int *b = new int[n];
    int i, j;
    for (i = 0; i < k; ++i)
    {
        int idx = 0;
        for (j = i; j < n; j += k)
            b[idx++] = a[j];

        sort(b, b + n);
        idx = 0;
        for (j = i; j < n; j += k)
            a[j] = b[idx++];
    }
    bool flag = true;
    for (i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
        {
            flag = false;
            break;
        }
    if(flag)
        cout<<"yes"<<endl;
    else 
        cout<<"no"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        solve(a, n, k);
    }
    return 0;
}
/*
2
4 1
1 4 2 3
4 2
1 4 2 3
*/