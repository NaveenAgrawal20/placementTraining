#include <iostream>
using namespace std;

int main()
{
    int a, b, c, ssmall;

        cin >> a >> b >> c;
        if(a > b && a > c)
            if (b > c)
                cout<<b<<"\n";
            else
                cout<<c<<"\n";
        else if (b > a && b > c)
            if (a > c)
                cout<<a<<"\n";
            else
                cout<<c<<"\n";
        else
            if (b > a)
                cout<<b<<"\n";
            else
                cout<<a<<"\n";  

    return 0;
}
/*
10 11 12
10 12 11
11 10 12
11 12 10
12 10 11
12 11 10
*/