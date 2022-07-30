#include <iostream>
#include <string>
#define endl "\n";

using namespace std;

void solve(string str,int len)
{
    if(len <= 0)
    {
        cout<<str<<endl;
        return;
    }
    for(char i = '1';i<='9';i++)
        solve(str+i,len-1);
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
        int n, i;
        cin >> n;
        string str = "";
        solve(str,n);
    }
    return 0;
}
