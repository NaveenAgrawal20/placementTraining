#include <bits/stdc++.h>
using namespace std;

int back(int t,int idx,bool vis[]){
    if(idx == t)
        return 1;
    int count = 0;
    for (int i = idx == 0?1:0; i < 10; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            count += back(t,idx+1,vis);
            vis[i] = false;
        }
    }
    return false;
}

int solve(int n){
    bool vis[10] = {false};
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        count += back(i,0,vis);
    }
    cout<<count<<"\n";
}


int main()
{
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}