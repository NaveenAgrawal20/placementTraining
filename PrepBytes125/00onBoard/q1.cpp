#include <bits/stdc++.h>
using namespace std;

int fun(int x,int y){
    if(x==0)
        return y;
    return fun(x-1,x+y);
}

int main()
{
    cout<<fun(1,3)<<endl;
    cout<<fun(2,3)<<endl;
}

/*Which of the following is true for GCD considering a>b?*/