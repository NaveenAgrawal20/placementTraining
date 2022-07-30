#include<iostream>
using namespace std;

typedef long long ll;

ll solve(ll cn,ll cs,ll low,ll high,ll x, ll y,ll k){
    if(low > high){
        return -1;
    }
    ll mid = (low+high)/2;
    if(cn+x*mid < cs+y*(k-mid)){
        return solve(cn,cs,mid+1,high,x,y,k);
    }
    else if(cn+x*mid > cs+y*(k-mid)){
        return solve(cn,cs,low,mid-1,x,y,k);
    }else{
        return mid;
    }
    
}

int main()
{
    int t = 1;
    cin>>t;
    while(t--){
        ll cn,cs,k,x,y;
        cin>>cn>>cs>>k>>x>>y;
        cout<<solve(cn,cs,1,k,x,y,k)<<'\n';
    }
    return 0;
}
/*
Time Limit
 1 second

Example
Sample Input
14 12 6 3 2

Sample Output
2

5
14 12 6 3 2
7 8 3 2 5
7 8 4 2 5
7 8 5 2 5
7 8 6 2 5
*/