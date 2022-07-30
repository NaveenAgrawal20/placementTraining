#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    int n,x;
    while(t--)
    {
        cin>>n>>x;
        int a[n-1],sum = 0;
        for(int i = 0;i<n-1;++i)
        {
            cin>>a[i];
            sum += a[i];
        }
        int ans = (n*x)-sum;
        if(ans <= 0)
            cout<<0<<'\n';
        else
            cout<<ans<<'\n';
    }
    return 0;
}
/*
3
3 4
1 5
4 2
5 8 6
3 1000
0 0
*/