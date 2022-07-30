#include <iostream>
#define endl "\n";

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int an1 = k - k % n;
        int an2 = k - k % m;
        int lcm = n*m/gcd(n,m);
        cout<<an1/lcm<<endl;
    }
    return 0;
}
