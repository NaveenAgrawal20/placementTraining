#include<iostream>
using namespace std;
string phone[10] = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

void solve(string s, int start,string ans) {
    if (start == s.length()){
        cout<<ans<<" ";
        return;
    }
    string t = phone[s[start]-'0'];
    for(int i = 0;i<t.length();i++){
        ans += t[i];
        solve(s,start+1,ans);
        ans.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s,ans="";
        cin>>s;
        solve(s, 0,ans);
        cout<<"\n";
    }
    return 0;
}
/*
2
97
27

Output
wp wq wr ws xp xq xr xs yp yq yr ys zp zq zr zs
ap aq ar as bp bq br bs cp cq cr cs*/