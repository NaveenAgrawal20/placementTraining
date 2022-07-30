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
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int left, right;
        for (left = 0; left < n - 1; left++)
            if (a[left] > a[left+1])
                break;
        for (right = n-1; right >= 1; right--)
            if (a[right] < a[right-1])
                break;

        int max = INT_MIN, min = INT_MAX;
        for(int i = left;i<=right;i++)
        {
            if(max < a[i])
                max = a[i];
            if(min > a[i])
                min = a[i];
        }
        for(int i = 0;i<left;i++)
            if(a[i] > min)
                left = i;

        for(int i = right;i<n;i++)
            if(a[i] < max)
                right = i;
        cout<<left<<" "<<right<<endl;
    }
    return 0;
}
/*
4
8
1 3 2 7 5 6 4 8
10
1 2 5 3 4 6 8 7 10 9
8
3 5 7 6 8 2 9 10
7
1 5 3 8 3 3 7
1 6
2 9
*/