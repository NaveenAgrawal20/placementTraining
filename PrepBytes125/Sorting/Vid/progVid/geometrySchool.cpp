#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"

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
        int *b = new int[n];
        for (int i = 0; i < n; i++)
            cin >>b[i];
        sort(a,a+n);
        sort(b,b+n);
        
        int sum = 0;
        for(int i = 0;i<n;i++)
            sum += min(a[i],b[i]);
        cout<<sum<<endl;
    }
    return 0;
}
/*

*/