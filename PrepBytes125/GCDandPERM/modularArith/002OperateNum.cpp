#include <iostream>
using namespace std;

int solve(int p, int q)
{
    if(p%q == 0)
        return p /q;
    else
        return p /q +solve(q,p%q);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int p, q;
        cin >> p >> q;
        cout << solve(p,q) << endl;
    }
    return 0;
}
/*
5
22 4
17 16
3 24
1 4
1000000000 10
*/