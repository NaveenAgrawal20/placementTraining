#include <iostream>
#include <climits>
using namespace std;

int reverse(int x)
{
    int rem = 0;

    while (x != 0)
    {
        if (rem > INT_MAX / 10 || rem < -2147483648 / 10 && x!=0)
            return 0;
        rem = rem * 10 + x % 10;
        x /= 10;
    }
    return rem;
}
int main()
{
    //2147483647
    //-2147483648


    //-1534236469
    //-9646324351
    //2147483641
    cout << reverse(-2147483648) << endl;
}