#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        cin >> n;
        int num;
        ll pos = 0, neg = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> num;
            if(num > 0)
                pos++;
            else if(num < 0)
                neg++;
        }
        ll ans = 0;
        // pos--;
        // neg--;
        // if(pos > 0)
        //     ans = (pos)*(pos+1)/2;
        // if(neg > 0)
        //     ans += (neg)*(neg+1)/2;
        ans = (neg*(neg-1))/2;
        ans += (pos*(pos-1))/2;
        cout<<ans<<'\n';
    }
    return 0;
}
/*
3
5
1 -3 0 2 -1
4
-1 -1 -1 -1
4
0 1 2 3
*/