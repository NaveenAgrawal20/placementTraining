#include <bits/stdc++.h>
using namespace std;
 
// Returns count of ways to color k posts
long countWays(int n, int k)
{
    long long mod = 1000000007;
 
    long long same = k*1;
    long long diff = k*(k-1);
    long long total = same+diff;

    for(int i = 3;i<=n;++i)
    {
        same = diff;
        diff = total * (k-1);
        total = (same+diff)%mod;
    }
    return total;
}
 
// Driver code
int main()
{
    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    cout << countWays(5, 3) << endl;
    cout << countWays(2, 3) << endl;
    cout << countWays(2, 4) << endl;
    return 0;
}