#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int n,m,k;
    while(t--)
    {
        cin>>n>>m>>k;
        if(m*k >= n)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}