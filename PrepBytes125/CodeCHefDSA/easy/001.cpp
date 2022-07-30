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
        int d,x,y,z;
        cin>>d>>x>>y>>z;
        cout<<max(7*x,d*y+(7-d)*z)<<endl;
    }
    return 0;
}
