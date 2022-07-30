#include <iostream>
using namespace std;

int main()
{
    int t, q;
    float p;
    cin >> t;
    while (t--)
    {
        cin >> q >>p;
        if( q > 100)
            p = p - p*0.2;
        p = q * p;
        printf("%.1f\n",p);      
    }
    return 0;
}
/*
5
100 120
200 100
200 115
215 115
212 93
*/