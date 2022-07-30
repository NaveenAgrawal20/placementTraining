#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T;
    ll n,p,k;
    cin>>T;
    while(T--){
        cin>>n>>p>>k;
        ll ans,x,maxRemCovDays;
        x = (p % k) - 1;
        maxRemCovDays = n - 1 - ((n-1)/k * k);
        if (x > maxRemCovDays)
            ans = (maxRemCovDays + 1) * ((n-1)/k + 1) + (x - maxRemCovDays) * (n - 1)/k;
        else
            ans = (x+1)*((n-1)/k + 1);
        for(int i = x+1;i<=n-1;i+=k){
            ans++;
            if(i == p){
                cout<<ans<<"\n";
                break;
            }
        }
    }
    return 0;
}