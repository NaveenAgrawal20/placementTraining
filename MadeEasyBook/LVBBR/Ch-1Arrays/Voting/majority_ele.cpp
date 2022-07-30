#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "<<x<<endl;
#else
#define debug(x)
#endif
void init_code()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);
    #endif
}

int maxInV(vector<int> &v)
{
    for(auto e:v)
        if (e < 10)
            return e;
    return -1;
}

int main()
{
    init_code();

    vector<int> v = {12,412,42,13,10,6,2};
    // using upper bound
    int a = maxInV(v);
    debug(a);
    cout<<a;
    return 0;
}