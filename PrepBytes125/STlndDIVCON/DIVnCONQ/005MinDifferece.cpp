#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> x;

        sort(a, a + n);
        int minDiff = INT_MAX;
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int currDiff = x - (a[i] + a[l] + a[r]);
                if (abs(currDiff) < minDiff)
                    minDiff = abs(currDiff);
                if (currDiff < 0)
                    r--;
                else
                    l++;
            }
        }
        cout << minDiff << endl;
    }
    return 0;
}
/*
3
5
1 2 5 9 12
15
4
-1 2 1 -4
1
5
1 2 3 4 -5
10
*/