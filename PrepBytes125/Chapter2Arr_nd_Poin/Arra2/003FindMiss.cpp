#include <iostream>
using namespace std;

// checking bitwise

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, i;
        cin >> n;
        int a[n-1]; // n-1 input
        int arrX = 0, totalX = 0;
        for (i = 0; i <= n - 2; i++)
        {
            cin >> a[i];
            arrX ^= a[i];
        }
        // xor for 1 to n.
        for (i = 1;i<=n;i++)
            totalX ^= i;
        
        cout<<(totalX ^ arrX)<<"\n";
    }
    return 0;
}
/*
2
4
1 3 4
7
1 2 5 4 6 7
*/