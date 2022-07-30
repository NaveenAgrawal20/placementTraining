#include <iostream>
using namespace std;
int main()
{
    int n = 9;
    int i, j;
    // let
    int a[n] = { 0,1,2,0,0,3,1,0,3 },water = 0;
    int left[n], right[n];
    left[0] = a[0];
    right[n-1] = a[n-1];
    for (i = 1; i < n; i++)
    {
        if (a[i] > left[i - 1])
            left[i] = a[i];
        else
            left[i] = left[i - 1];
    }
    for (i = n - 2; i >= 0; i--)
    {
        if (a[i] > right[i+1])
            right[i] = a[i];
        else
            right[i] = right[i + 1];
    }
    for (i = 0; i < n; i++)
        water += min(left[i],right[i]) - a[i];
    cout << water << endl;
}
