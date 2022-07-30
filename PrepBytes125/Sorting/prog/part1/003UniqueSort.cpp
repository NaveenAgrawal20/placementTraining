#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"

int solve(int *a,int low,int high)
{
    if(low == high)
        return 1;
    int mid = (high+low)/2;
    int h1 = solve(a,low,mid);
    int h2 = solve(a,mid+1,high);
    if(h1 == h2 && h2 == (high-low+1)/2 && a[mid] <= a[mid+1])
        return high-low+1;
    else 
        return max(h1,h2);
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
            cin >> a[i];
        cout<<solve(a,0,n-1)<<endl;
    }
    return 0;
}
/*
5
4
1 2 2 4
8
11 12 1 2 13 14 3 4
4
7 6 5 4
1
1
2
5 1
*/