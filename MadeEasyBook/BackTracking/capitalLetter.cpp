#include<iostream>
#include<bitset>

using namespace std;

void solve(string s, int start) {
    if (start == s.length()) {
        cout << s << "\n";
        return;
    }
    if (s[start] >= '0' && s[start] <= '9'){
        solve(s, start + 1);
        return;
    }
    s[start] -= 32;
    solve(s,start+1);
    s[start] += 32;
    solve(s,start+1);
}
int main() {
    string s;
    cin>>s;
    solve(s, 0);
    return 0;
}
//
//Output
//BYT1E
//BYT1e
//BYt1E
//BYt1e
//ByT1E
//ByT1e
//Byt1E
//Byt1e
//bYT1E
//bYT1e
//bYt1E
//bYt1e
//byT1E
//byT1e
//byt1E
//byt1e
