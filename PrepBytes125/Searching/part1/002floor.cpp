#include <iostream>
#define endl "\n"
using namespace std;

int solve(int a[], int low, int high,int data)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] <= data && (mid == high || a[mid + 1] > data))
        return mid;
    else if(a[mid] > data)
        return solve(a,low,mid-1,data);
    else
        return solve(a,mid+1,high,data);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int T;
    cin >> T;
    while (T--)
    {
        int n,k;
        cin >> n >> k;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout <<solve(a, 0, n - 1,k) << endl;
    }
    return 0;
}