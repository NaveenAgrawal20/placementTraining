#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;
int n;
int solve2(int *a, int low, int high, int key)
{
    int mid = low + (high - low) / 2;
    
    if (a[mid] == key || low >= high)
        return a[mid];
    if (a[mid] > key)
    {
        if (mid != 0 && a[mid - 1] < key)
        {
            return a[mid] - key < key - a[mid-1] ? a[mid] : a[mid-1];
        }
        else{
            return solve2(a,low,mid-1,key);
        }
    }else{
        if (mid != n-1 && a[mid + 1] > key)
        {
            return key - a[mid] < a[mid+1] - key ? a[mid] : a[mid+1];
        }else{
            return solve2(a,mid+1,high,key);
        }
    }
}

int solve(int *a, int n, int key)
{
    int diff = key, idx;
    for (int i = 0; i < n; i++)
    {
        if (abs(key - a[i]) < diff)
        {
            diff = abs(key - a[i]);
            idx = i;
        }
    }
    return a[idx];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int i, j, k;
        cin >> n >> k;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve2(a, 0, n - 1, k) << endl;
    }
}
/*
2
7 11
1 2 4 5 6 8 9
7 4
2 5 6 7 8 8 9
*/