#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n], t[n], tsize = 1;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        t[0] = a[n - 1];
        // result array
        int k = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (t[k] <= a[i])
            {
                t[++k] = a[i];
                tsize++;
            }
        }
        // printing result
        for (int i = 0; i < tsize; i++)
            cout<< t[i]<<" ";
        cout<<"\n";
    }

    return 0;
}
/*
2
5
1 2 3 4 5
4
1 4 3 2
*/
/*
5
2 3 4*/