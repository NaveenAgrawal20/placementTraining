#include<iostream>
#include<bitset>

using namespace std;


void solve(string s,int start, int n) {
    unsigned long hours = bitset<4>(s.substr(6,4)).to_ulong();
    if (hours > 11)
        return;

    unsigned long minutes = bitset<6>(s.substr(0,6)).to_ulong();
    if (minutes > 59)
        return;
    if (n == 0){
        cout << hours<<":"<<(minutes < 10 ? "0"+to_string(minutes):to_string(minutes))<<" ";
        return;
    }
    if(start == s.length()){
        return;
    }

    for(int i = start;i<10;i++){
        s[i] = '1';
        solve(s,i+1,n-1);
        s[i] = '0';
    }
}

int main(){
    int n;
    cin>>n;
    string s = "0000000000";
    solve(s,0,n);
    return 0;
}
