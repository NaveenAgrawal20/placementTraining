#include<iostream>
using namespace std;

int getSocks(int pair){
    if(pair == 1)
        return 2;
    return pair+1;
}

int main()
{
    int t,pair,socks;
    cin>>t;
    while(t--){
        cin>>pair;
        cout<<getSocks(pair)<<"\n";
    }
    return 0;
}
