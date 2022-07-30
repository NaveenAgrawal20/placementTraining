#include <iostream>
#include <string>
#define endl "\n";
typedef long long int ll;

using namespace std;

ll fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
int fib(int n)
{
    if(n<=2)
        return 1;
    return fib(n-2)+fib(n-1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, i;
        cin >> n;
        cout<<fib(n)<<" ";
    }
    return 0;
}
/*
14
1 2 3 4 5 6 7 8 9 10 11 12 19 20
*/