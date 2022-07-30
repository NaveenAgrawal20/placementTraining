#include <bits/stdc++.h>

using namespace std;
double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    double temp = myPow(x, n / 2);
    if (n % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        if (n < 0)
        {
            return temp * temp /x;
        }
        return x * temp * temp;
    }
}
int main()
{
    cout << pow(2, 2) << "\n";
    cout << pow(2, 3) << "\n";
    cout << pow(2, 4) << "\n";
    cout << pow(2, -2) << "\n";
    cout << "-------------"
         << "\n";
    cout << myPow(2, 2) << "\n";
    cout << myPow(2, 3) << "\n";
    cout << myPow(2, 4) << "\n";
    cout << myPow(2, -2) << "\n";
    cout << myPow(2, -3) << "\n";
    cout << 2/2 << "\n";
    return 0;
}