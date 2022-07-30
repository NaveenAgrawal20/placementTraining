#include <iostream>
#include <math.h>
#define endl "\n";
using namespace std;

int firstDigit(int r)
{
    int d = (int)log10(r);
    return r / pow(10, d);
}
int isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;

    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int N, k;
    cin >> N >> k;
    while (N--)
    {
        int flag = 0;
        int r;
        cin >> r;
        int lDig = r % 10;
        int fDig = firstDigit(r);
        int sum = lDig + fDig;
        if (sum >= k)
        {
            if (isPrime(lDig) && isPrime(fDig))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}