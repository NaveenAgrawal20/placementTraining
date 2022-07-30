#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"

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
            cin >> a[i];
        sort(a,a+n);
        int sum = 0;
        for(int i = n-1;i>=0;i-=2)
            sum += a[i];
        cout<<sum<<endl;
    }
    return 0;
}