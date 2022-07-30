#include <bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, i, j;
        scanf("%d", &n);
        int a[n];
        int ans = 0;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int evenOp = 0, oddOp = 0, prev, next;
        for (i = 0; i < n; i++)
        {
            prev = i == 0 ? INT_MAX : a[i - 1];
            next = i == n - 1 ? INT_MAX : a[i + 1];
            if (i % 2 == 0) // form2
            {
                if (a[i] >= min(prev, next))
                    evenOp += a[i] - min(prev, next) + 1;
            }
            else // form1
            {
                if (a[i] >= min(prev, next))
                    oddOp += a[i] - min(prev, next) + 1;
            }
        }
        cout << min(evenOp, oddOp) << "\n";
    }

    return 0;
}
/*
10
4
14 8 6 9
4
10 7 2 7
3
2 3 4
5
10 7 2 7 3
*/