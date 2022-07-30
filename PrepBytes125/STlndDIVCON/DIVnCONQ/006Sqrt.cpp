#include <iostream>
using namespace std;

typedef long long ll;
#define endl "\n"

int solve(int low, int high, ll n)
{
    ll mid = (high + low) /2;
    if(low > high)
        return mid;   
    if(mid * mid > n)
        return solve(low,mid-1,n);
    else
        return solve(mid+1,high,n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;

        cout << solve(1, n,n) << endl;
    }
    return 0;
}
/*
7
1
2
9
16
17
3136
10000000000
*/