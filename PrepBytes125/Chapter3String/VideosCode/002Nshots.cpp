#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, i;
        cin >> n;
        string shots;
        cin >> shots;

        int aC = 0, bC = 0, achance = n, bchance = n;
        for (i = 0; i < 2 * n; i++)
        {
            if (i % 2 == 0)
            {
                achance--;
                if (shots[i] == '1')
                    aC++;
            }
            else
            {
                bchance--;
                if (shots[i] == '1')
                    bC++;
            }
            if (aC - bC > bchance)
            {
                cout<<i+1<<"\n";
                break;
            }
            else if (bC - aC > achance)
            {
                cout<<i+1<<"\n";
                break;
            }
            else if (i == 2 * n - 1)
                cout<<i+1<<"\n";
        }
    }

    return 0;
}
/*
5
3
101011
3
100001
4
10101010
4
01010101
3
000001
*/