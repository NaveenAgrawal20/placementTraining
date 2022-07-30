#include <iostream>
#include <string>
#define endl "\n";
using namespace std;

int solve(int a[], int i, int k,int n)
{
    if (i >= n && k != 0) // no case found
        return 0;
    if (k == 0) // result found
        return 1;

    int addO = solve(a, i + 1, k + a[i],n);
    int subO = solve(a, i + 1, k - a[i],n);
    int ign = solve(a, i + 1, k,n);
    return (addO + subO + ign);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(a, 0, k,n) << endl;
    }
    return 0;
}
/*
3
3 2
1 3 2
4 6
5 3 -6 2
4 2
1 3 2 6

 I am processing array elements from (last index (li) `n-1`)  with K as the required value.
I will check for three cases by 
1. considering the current element and Add it to k
2. considering the current element and Sub it from k
3. and by not considering the current 
If at any point `k = 0` then I will rerturn 1.
and if after processing all elements ( when li < 0) and k != 0 then I will return 0.
*/