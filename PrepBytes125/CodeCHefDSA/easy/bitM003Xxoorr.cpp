#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int i, j, n, k;
        cin >> n >> k;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];


        vector<int> bitArr(32);
        for (i = 0; i < 32; i++)
        {
            int count = 0;
            for (j = 0; j < n; j++)
            {
                if (a[j] % 2 != 0)
                {
                    count++;
                }
                a[j] /= 2;
            }
            bitArr[i] = count;
        }
        int ans = 0;
        for(int& bitNum:bitArr)
        {
            if(bitNum %k  == 0)
                ans += bitNum/k;
            else
                ans += bitNum/k + 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
