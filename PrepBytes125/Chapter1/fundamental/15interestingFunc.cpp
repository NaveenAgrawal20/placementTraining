#include <iostream>
#include <climits>
using namespace std;

long long int InterestingFunc(long long int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        return InterestingFunc(n / 2);
    else
        return InterestingFunc(n - 1) + 1;
}

int main()
{
    int t;
    cin >> t;
    long long int n;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        cout << InterestingFunc(n);
    }

    return 0;
}