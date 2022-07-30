#include <iostream>
#include <string>
#define endl "\n";

using namespace std;

void print(int a[], int siz)
{
    for (int i = 0; i < siz; i++)
        cout << a[i];
    cout << endl;
}

void binary(int a[], int idx, int n)
{
    if (idx == n)
    {
        print(a, n);
        return;
    }
    if (a[idx - 1] == 1)
    {
        a[idx] = 0;
        binary(a, idx+1, n);
    }else{
        a[idx] = 0;
        binary(a, idx+1, n);
        a[idx] = 1;
        binary(a, idx+1, n);
    }
}

void solve(int n)
{
    int i, a[n];
    a[0] = 0;
    binary(a, 1, n);
    a[0] = 1;
    binary(a, 1, n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, i;
        cin >> n;
        solve(n);
    }
    return 0;
}