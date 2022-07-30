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
        
        sort(a,a+n);
        long long sum = 0;
        for(int i = 0;i<n;i++)
            sum += abs(a[i] - (i + 1));
        cout<<sum<<endl;
    }
    return 0;
}
/*

*/