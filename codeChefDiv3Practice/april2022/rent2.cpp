#include <iostream>
using namespace std;

int main()
{
    int t, r, m, c;
    cin >> t;
    while (t--)
    {
        cin >> r >> c;
        if (r >= c)
        {
            cout << 0 << '\n';
            continue;
        }
        m = c / r;
        if (m * r < c)
            cout << m << '\n';
        else
            cout<<m-1<<'\n';
    }
    return 0;
}
