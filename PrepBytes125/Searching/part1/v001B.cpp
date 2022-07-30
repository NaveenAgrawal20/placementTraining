#include <iostream>
#define endl "\n"
using namespace std;

int solve(int a[], int low, int high)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == 1 && (mid == 0 || a[mid - 1] == 0))
        return mid;
    else if(a[mid] != 1)
        return solve(a,mid+1,high);
    else
        return solve(a,low,mid-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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
        cout <<n- solve(a, 0, n - 1) << endl;
    }
    return 0;
}