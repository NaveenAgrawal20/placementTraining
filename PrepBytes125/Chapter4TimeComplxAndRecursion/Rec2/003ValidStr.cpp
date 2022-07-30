#include <iostream>
#include <string>
#define endl "\n";

using namespace std;

void solve(string str,int sidx,int eidx)
{
    if(sidx == eidx)
    {
        cout<<"Yes"<<endl;
        return;
    }
    else if(str[sidx] != str[eidx])
    {
        cout<<"No"<<endl;
        return;
    }
    else
    {
        solve(str,sidx+1,eidx-1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin>>str;
        solve(str,0,str.size()-1);
    }
    return 0;
}
