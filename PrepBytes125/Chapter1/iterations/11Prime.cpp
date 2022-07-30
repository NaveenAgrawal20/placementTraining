#include <iostream>
#include <math.h>
using namespace std;

// 210 = 2*3*5*7
int main()
{
    int rem[] = {50, 80, 170, 20, 200, 110};
    int p = 6; //size of array rem

    int n;
    cin >> n;
    if (n <= 2)
        cout << -1 << "\n";
    else if (n == 3)
        cout << 210 << "\n";
    else
    {
        cout << 1;
        for (int i = 1; i <= n - 4; i++)
            cout << 0;
        printf("%03d\n", rem[(n % 6 + 2) % 6]);
    }
}
/*
1000000
*/