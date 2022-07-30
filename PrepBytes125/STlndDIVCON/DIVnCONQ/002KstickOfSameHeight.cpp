#include <iostream>
using namespace std;

typedef long long ll;
#define endl "\n"

int solve(int *a, int low, int high, int n, int k)
{
    int mid = (low + high) / 2;
    ll sum = 0;
    if (low > high)
        return mid;
    for (int i = 0; i < n; i++)
        sum += a[i] / mid;
    if (sum < k)
        return solve(a, low, mid - 1, n, k);
    else
        return solve(a, mid + 1, high, n, k);
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
        cout << solve(a, 1, 1e9, n, k) << endl;
    }
    return 0;
}
/*
2
3 4
15 10 8
3 4
100 5 10
*/