#include <iostream>
using namespace std;

int extendedGcd(int a,int b,int &x,int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1,y1;
    int result = extendedGcd(b,a%b,x1,y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a = 56,b = 21;
    int result,x,y;
    x = y = 0;
    result = extendedGcd(a,b,x,y);
    cout << result << " " << x << " " << y;
    return 0;
}
/*
o/p => 7 -1 3
*/