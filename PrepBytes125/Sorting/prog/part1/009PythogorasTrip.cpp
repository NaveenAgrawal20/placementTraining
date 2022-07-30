#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"
typedef long long ll;
bool solve(ll *a, int n)
{
    sort(a, a + n);
    for(int i = n-1;i>=2;i--)
    {
        int l = 0,r = i-1;
        while(l<=r)
        {
            if(a[l]+a[r] == a[i])
                return  true;
            else
                a[l]+a[r] < a[i]?l++:r--;
        }
    }
   
    return false;
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
        ll *a = new ll[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0;i<n;i++)
            a[i] = a[i]*a[i];
        cout << (solve(a, n)?"Yes":"No")<< endl;
    }
    return 0;
}
