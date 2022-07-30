#include<bits/stdc++.h>
using namespace std;
void createZarr(string st, int z[]){
    int l = 0, r = 0, n = st.length();
    for (int i = 1; i < n; ++i) {
        if(i > r){
            l = r = i;
            while(r < n && st[r-l] == st[r])
                r++;
            z[i] = r - l;
            r -= 1;
        }
        else{
            int k = i - l;
            if(z[k] < r-i+1)
                z[i] = z[k];
            else{
                l = i;
                while(r < n  && st[r - l] == st[r])
                    r++;
                z[i] = r - l;
                r -= 1;
            }
        }
    }
}

void z_algo(string text,string pattern){
    int n = pattern.length();
    string st = pattern.append("$").append(text);
    int len = st.length();
    int z[len];
    memset(z,0,len);
    createZarr(st,z);
    for (int i = 0; i < len; ++i) {
        if(z[i] == n){
            cout<<"Pattern found at index "<<i-(n+1)<<"\n";
        }
    }
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        string text,pattern;
        cin>>text>>pattern;
        z_algo(text,pattern);
    }
}
/*
1
aabzabaabzabaab
aab
 */