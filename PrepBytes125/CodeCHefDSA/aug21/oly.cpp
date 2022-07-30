#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T,a,b,c,g,h,i;
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>g>>h>>i;
        if(a+b+c > g+h+i)
            cout<<1<<"\n";
        else
            cout<<2<<"\n";
    }
    return 0;
}