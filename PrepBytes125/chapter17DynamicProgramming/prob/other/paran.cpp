#include<iostream>
using namespace std;
typedef long long ll;

ll dp[41][41];
ll solve2(int l,int r){
    if (l < 0 || r < 0)
        return 0;
    if(l == 0 && r == 0)
    {
        dp[l][r] = 1;
        return 1;
    }
    if(dp[l][r] != 0)
        return dp[l][r];

    ll sum = 0;
    if(l < r)
        sum += solve2(l,r-1);
    if(l > 0)
        sum += solve2(l-1,r);
    dp[l][r] = sum;
    return dp[l][r];
}
int solve1(int l,int r){
    if(l < 0 || r < 0)
        return 0;
    if(l == 0 && r == 0)
        return 1;
    int sum = 0;
    if(l<r)
        sum += solve1(l,r-1);
    if(l>0)
        sum += solve1(l-1,r);
    return sum;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // cout<<solve1(n/2,n/2)<<"\n";
        cout<<solve2(n/2,n/2)<<"\n";
    }
    return 0;
}