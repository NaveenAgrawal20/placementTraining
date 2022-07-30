#include <iostream>
#define endl "\n"
using namespace std;

int solve(int *a, int low, int high)
{
    int mid = low + (high - low) / 2;
    if ((mid == low || a[mid] >= a[mid - 1]) && (mid == high || a[mid] >= a[mid + 1]))
        return mid;
    else if (mid > low && a[mid] < a[mid - 1])
        return solve(a, low, mid - 1);
    else
        return solve(a, mid + 1, high);
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
        cout << solve(a, 0, n - 1) << endl;
    }
    return 0;
}