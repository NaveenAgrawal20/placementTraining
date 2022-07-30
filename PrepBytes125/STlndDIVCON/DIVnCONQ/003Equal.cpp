#include <iostream>
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
        int n, k, i;
        cin >> n >> k;
        int* a = new int[n];
        for (i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);
        int* freq = new int[a[n - 1]+1]();
        for (i = 0; i < n; i++)
            freq[a[i]]++;

        int min = a[0];
        int max = a[n - 1];
        int count = 0;
        while (abs(max - min) > k)
        {
            freq[min]--;
            freq[min + 1]++;
            freq[max]--;
            freq[max - 1]++;
            if (freq[min] == 0)
                min++;
            if (freq[max] == 0)
                max--;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
/*
1
4 3
1 5 1 10
*/