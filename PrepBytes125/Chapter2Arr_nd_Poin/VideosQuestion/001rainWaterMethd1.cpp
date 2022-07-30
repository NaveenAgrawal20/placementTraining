#include <iostream>
using namespace std;

// Method 1
int main()
{
    int n = 9, i, j;
    // let
    int a[9] = { 1,8,6,2,5,4,8,3,7};
    // int a[9] = {0, 1, 2, 0, 0, 3, 1, 0, 3};
    int lMax = a[0], rMax = a[n - 1], water = 0;
    for (i = 1; i < n; i++)
    {
        for (j = i; j >= 0; j--)
            if (lMax < a[j])
                lMax = a[j];
        for (j = i; j <= n - 2; j++)
            if (rMax < a[j])
                rMax = a[j];
        water += min(lMax, rMax) - a[i]; //a[i] = height
    }
    cout << water << endl;
}
