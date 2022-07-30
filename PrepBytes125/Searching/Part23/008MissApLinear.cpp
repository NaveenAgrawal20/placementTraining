#include <iostream>
#define endl "\n"
using namespace std;

// TC  = O(n)
int solve(int a[], int n)
{
    int i ,d = (a[n - 1] - a[0]) / n;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] != d)
            break;
    }
    return a[i] + d;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve(a, n) << endl;
    }
    return 0;
}