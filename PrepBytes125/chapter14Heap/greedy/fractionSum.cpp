#include<iostream>
using namespace std;

void solve(int n,int d){
    if(n == 0 || d == 0)
        return;
    if(d%n == 0){
        cout<<d/n<<" ";
        return;
    }
    if(n%d == 0){
        cout<<"1/"<<n/d<<" ";
        return;
    }
    
    if(n > d){
        cout<<"1/"<<n/d<<" ";
        solve(n%d,d);
        return;
    }
    int x = d/n + 1;
    cout<<x<<" ";
    solve(n*x-d,d*x);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        solve(n,d);
    }
    return 0;
}