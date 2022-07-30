#include <iostream>
using namespace std;

int main()
{
    int t, b, n;
    cin >> t;
    while (t--)
    {
        cin >> b;
        switch(b%8)
        {
            case 0:
                cout<<b-1<<"SL"<<"\n";break;
            case 1:
                cout<<b+3<<"LB"<<"\n";break;
            case 4:
                cout<<b-3<<"LB"<<"\n";break;
            case 2:
                cout<<b+3<<"MB"<<"\n";break;
            case 5:
                cout<<b-3<<"MB"<<"\n";break;
            case 3:
                cout<<b+3<<"UB"<<"\n";break;
            case 6:
                cout<<b-3<<"UB"<<"\n";break;
            case 7:
                cout<<b+1<<"SU"<<"\n";break;
        }
        
    }
    return 0;
}