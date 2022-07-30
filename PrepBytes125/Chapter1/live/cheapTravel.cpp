#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,m,a,b,price = 0,rem;
    cin>>n>>m>>a>>b;
    if(m*a < b)
    {
        price = n*a;
    }
    else{
        if(n%m == 0)
            price = n/m * b;
        else{
            rem = n % m;
            price  = n/m * b + min(rem*a,b);
        }
    }
    cout<<price<<" ";
    return 0;
}