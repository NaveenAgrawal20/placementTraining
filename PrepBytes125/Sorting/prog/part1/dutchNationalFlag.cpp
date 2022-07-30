#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"
void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void dutchNatFlagSort(int *a,int n)
{
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
        if (a[j] < 1)
        {
            swap(a[i], a[j]);
            i++;
            j++;
        }
        else if (a[j] > 1)
        {
            swap(a[k], a[j]);
            k--;
        }
        else
            j++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int mid = n / 2;
        dutchNatFlagSort(a, n);
        display(a, n);
    }
    return 0;
}
/*
1
9
0 1 0 1 0 2 2 0 1
*/