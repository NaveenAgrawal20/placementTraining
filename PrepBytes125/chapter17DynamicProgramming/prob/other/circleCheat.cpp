#include <iostream>
using namespace std;

int solve(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += solve(i) * solve(n - i - 1);
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n / 2) << "\n";
    }
    return 0;
}