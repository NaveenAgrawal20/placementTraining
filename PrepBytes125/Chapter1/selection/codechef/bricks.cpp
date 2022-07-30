#include<iostream>
using namespace std;

int main()
{
    int t,s,w1,w2,w3,hit;
    cin>>t;
    while(t--){
        cin>>s>>w1>>w2>>w3;
        if(w1+w2+w3 <= s)
            cout<<1<<"\n";
        else if(w1+w2 <= s || w3+w2 <= s){
            cout<<2<<"\n";
        }else{
            cout<<3<<"\n";
        }
    }
    return 0;
}