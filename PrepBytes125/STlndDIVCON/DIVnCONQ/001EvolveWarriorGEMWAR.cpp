#include <iostream>
using namespace std;

typedef long long ll;
#define endl "\n"

int solve(ll n, ll low, ll high, ll m, int x, int y)
{
    ll mid = (high + low)/2;
    if (low > high)
        return mid;
    if(mid * x <= m + (n - mid)*y)
        return solve(n,mid+1,high,m,x,y);
    else
        return solve(n,low,mid-1,m,x,y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        ll n, m;
        int  x, y;
        cin >> n >> m >> x >> y;
        cout << solve(n, 0, n, m, x, y) << endl;
    }
    return 0;
}
/*
2
12 10 4 3
3 10 4 2
*/