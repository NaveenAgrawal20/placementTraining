#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int solve(int a[], int n, int k)
{
    sort(a, a + n);
    int l = 0, r = 0, count = 0;

    while (r < n)
    {
        int diff = a[r] - a[l];
        if (diff == k)
        {
            count++;
            if(a[l] == a[l+1])
                l++;
            else
                r++;
        }
        else if (diff > k)
            l++;
        else
            r++;
    }
    return count;
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
        int n, k;
        cin >> n >> k;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve(a, n, k) << endl;
    }
    return 0;
}
/*
1
4 3
1 1 1 4

https://www.geeksforgeeks.org/find-the-gcd-that-lies-in-given-range/

https://www.geeksforgeeks.org/maximize-median-after-doing-k-addition-operation-on-the-array/
*/