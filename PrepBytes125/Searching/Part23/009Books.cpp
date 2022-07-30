#include <iostream>
#define endl "\n"
using namespace std;

int solve(int a[], int n,int k)
{
    int low = 0,high = n-1,count = 0;
    while(low <= high)
    {
        if(a[low] > k && a[high] > k)
            return n - count;
        if(a[low] <= k)
        {
            low++;
            count++;
        }
        else if(a[high] <= k)
        {
            high--;
            count++;
        }
    }
    return n - count;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int T;
    // cin >> T;
    // while (T--)
    // {
        int n,k;
        cin >> n >> k;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << solve(a, n,k) << endl;
    // }
    return 0;
}
/*
Output:
Print a single integer denoting the number of pairs.

Constraints:
2≤n≤10^5
0<k,arr[i]<10^9

Time Limit:
1 second

Example
Input
5 2
1 5 3 4 2

Output
3

Sample test case explanation
The pairs are 
(
1
,
3
)
, 
(
2
,
4
)
 and 
(
3
,
5
)
.

https://www.geeksforgeeks.org/count-pairs-difference-equal-k/
*/