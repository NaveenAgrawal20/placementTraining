#include <iostream>
using namespace std;

int main()
{
    int t, m,n;
    cin >> t;
    while (t--)
    {
        cin>>m>>n;
        m = m * n;
        cout<<m/2<<"\n";
    }
    return 0;
}
/*
2
2 5
5 2
*/