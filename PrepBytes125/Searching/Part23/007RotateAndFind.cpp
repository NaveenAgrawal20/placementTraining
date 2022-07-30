#include <iostream>
#define endl "\n"
using namespace std;

int solve(int a[], int low, int high, int data)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    
    if (a[mid] == data)
        return mid;

    // check left array if sorted
    if (a[mid] >= a[low])
    {
        if (a[mid] >= data && data >= a[low])
            return solve(a, low, mid - 1, data);    
        return solve(a, mid + 1, high, data);
    }

    //if left not sorted than right will be
    if (a[mid] <= data && data <= a[high])
        return solve(a, mid + 1, high, data);
    return solve(a, low, mid - 1, data);
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
        {
            cin >> a[i];
        }
        int data;
        cin >> data;
        cout << solve(a, 0, n - 1, data) << endl;
    }
    return 0;
}
/*
3
9
5 6 7 8 9 10 1 2 3
10
3
3 1 2
1
4
3 5 1 2
6
*/