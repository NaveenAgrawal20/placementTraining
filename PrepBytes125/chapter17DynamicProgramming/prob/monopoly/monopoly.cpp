#include<iostream>
using namespace std;

int solve(int *a,int l,int r)
{
    if(l+1 == r)
        return max(a[l],a[r]);
    return max(a[l] + min(solve(a,l+2,r),solve(a,l+1,r-1)),
                a[r]+min(solve(a,l,r-2),solve(a,l+1,r-1))
                );
}

int dp[101][101];
int solveDP(int *a,int l,int r){
    if(r < l)
        return 0;
    if(l+1 == r)
        return max(a[l],a[r]);
    if(dp[l][r])
        return dp[l][r];
    dp[l][r] = max(a[l] + min(solve(a,l+2,r),solve(a,l+1,r-1)),
                a[r]+min(solve(a,l,r-2),solve(a,l+1,r-1))
                );
    return dp[l][r];
}
void filldp(){
    for(int i = 0;i<101;i++)
        for(int j = 0;j<101;j++)
            dp[i][j] = 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        filldp();
        for(int i = 0;i<n;i++)
            cin>>a[i];
        cout<<solveDP(a,0,n-1)<<"\n";
    }
    return 0;
}