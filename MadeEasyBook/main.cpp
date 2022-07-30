#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int solve(ll g[],ll c[],int n){
    int i;
    ll cost,gidx;
    for(i = 0;i<n;i++){
        if(g[i] >= c[i])
        {
            gidx = i;
            cost = g[i] - c[i];
            break;
        }
    }
    ll currCost = 0;
    if(i == n)
        return -1;
    i = (gidx + 1) % n;
    do{
        currCost = g[i] + cost - c[i];
        if(currCost >= 0)
            cost = currCost;
        else
            break;
        i = (i+1)%n;
    }while(i != gidx);
    if(i != gidx)
        return -1;
    return i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 6;
    while(T--)
    {
        int n;
        cin>>n;
        ll g[n],c[n];
        for(int i = 0;i<n;i++)
            cin>>g[i];
        for(int i = 0;i<n;i++)
            cin>>c[i];

        ///////////////////
        cout<<solve(g,c,n)<<"\n";
    }
    return 0;
}
/*
4
4 6 7 4
6 5 3 5
5
1 2 3 4 5
3 4 5 1 2
5
1 2 3 4 5
3 4 5 1 5
5
1 2 3 4 5
3 4 5 5 5
3
2 3 4
3 4 3
5
1 2 3 4 5
3 4 7 1 2
5
5 1 2 3 4
4 4 1 5 1
*/