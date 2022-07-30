#include <iostream>
using namespace std;
#define N 6
#define MAX 99999;
int D[N] = {1, 5, 10, 20, 25, 50};

// int solve(int amt, int n)
// {
//     if (n == 1)
//         return amt;
//     if (D[n - 1] <= amt)
//     {
//         int l = solve(amt - D[n - 1], n)+1;
//         int r = solve(amt, n - 1);
//         int t1 = min(l,r);        
//         return t1;
//     }
//     // else
//     int t2 = solve(amt, n - 1);
//     return t2;
// }

int solve(int amt,int n)
{
    if(amt == 0)
        return 0;
    int res = MAX;
    int s_res = 0;
    for(int i = 0;i<n;i++)
    {
        if(D[i] <= amt)
            s_res = solve(amt-D[i],n);
    }
    res = min(s_res,res) + 1;
    return res;
}
int main()
{
    int t = 3;
    cin>>t;
    while (t--)
    {
        int amt;
        cin >> amt;
        int n = N;
        cout << "Total Denomination = " << solve(amt, n) << '\n';
    }
    return 0;
}
/*
55
55
Total Denomination = 2
45
Total Denomination = 2
37
Total Denomination = 4
98
Total Denomination = 6
44
Total Denomination = 6
10
Total Denomination = 1
1
Total Denomination = 1
2
Total Denomination = 2
3
Total Denomination = 3
4
Total Denomination = 4
5
Total Denomination = 1
6
Total Denomination = 2
7
Total Denomination = 3
8
Total Denomination = 4
9
Total Denomination = 5
10
Total Denomination = 1
13
Total Denomination = 4
15
Total Denomination = 2
16
Total Denomination = 3
20
Total Denomination = 1
25
Total Denomination = 1
22
Total Denomination = 3
30
Total Denomination = 2
45
Total Denomination = 2
54
Total Denomination = 5
55
Total Denomination = 2
54
Total Denomination = 5
100
Total Denomination = 2
10423
*/