#include<iostream>
using namespace std;

typedef long long int ll;
int main()
{
    int T;
    cin >> T;
    while(T--){
        ll n,m,s;
        cin>>n>>m;
        s = n * m;
        if(s%2 == 0)
            cout<<"Yes"<<"\n";
        else
            cout<<"No"<<"\n";
    }
    return 0;
}