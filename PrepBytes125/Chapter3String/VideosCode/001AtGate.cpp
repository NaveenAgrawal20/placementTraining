#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, k, i;
        cin >> n >> k;
        char coins[n];
        for (i = 0; i < n; i++)
            cin >> coins[i];

        for (i = n - 1; i >= n - k; i--)
        {
            if (coins[i] == 'H')
            {
                for (int j = 0; j < i; j++)
                {
                    if(coins[j] == 'H')
                        coins[j] = 'T';
                    else
                        coins[j] = 'H';
                }
            }
        }
        int countH = 0;
        for(i = 0;i<n-k;i++)
            if(coins[i] == 'H')
                countH++;
        
        cout<<countH<<"\n";
    }

    return 0;
}