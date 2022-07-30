#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        int ans = gcd(a,b);
        ans = ans * ans;
        cout<<(a*b)/ans<<"\n";
    }
    return 0;
}