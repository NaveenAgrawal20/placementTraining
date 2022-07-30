#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int rem = 0;
    while (x > rem)
    {
        rem = rem * 10 + x % 10;
        x = x / 10;
    }
    return x == rem || x == rem / 10;
}
int main()
{                      //1534236469
                       //2147483647
                       //964632435
    cout << isPalindrome(2345678991);
                        //  2147483647
}