#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, swap;
        cin >> n;
        long long int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        for (int i = 0; i < n - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
                swap++;
            if (i < n - 2 && arr[i] > arr[i+2])
                swap++;
            if(swap > 2)
                break;
        }
        if(swap > 1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}