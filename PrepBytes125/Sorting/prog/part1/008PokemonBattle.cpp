#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define endl "\n"
#define MAX 99999

int solve(int *a, int *b, int n)
{
    int count = 0;
    sort(a, a + n);
    sort(b, b + n);
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (a[i] > b[j])
        {
            count++;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        int *b = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        cout << solve(a, b, n) << endl;
    }
    return 0;
}
