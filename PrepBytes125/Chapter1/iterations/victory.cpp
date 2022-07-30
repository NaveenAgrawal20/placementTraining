#include<iostream>
using namespace std;

int main()
{
    int T,l,r;
    cin>>T;
    while(T--){
        cin>>l>>r;
        if(l == r)
            cout<<l<<"\n";
        else
            cout<<1<<"\n";
    }

    return 0;
}