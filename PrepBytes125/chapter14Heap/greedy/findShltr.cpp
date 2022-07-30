#include<iostream>
#include<string>
using namespace std;

string solve(string s,int m)
{
    int count = 0;
    while(count < m){
        int n = s.length();
        for(int i = 0;i<n - 1;i++){
            if(s[i] < s[i+1]){
                s.erase(s.begin()+i);
                count++;
                break;
            }
            else if((i+1 == n - 1) && s[i] >= s[i+1])
            {
                s.erase(s.begin()+i+1);
                count++;
                break;
            }
        }
    }
    return s;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int m;
        string s;
        cin>>s>>m;
        cout<<solve(s,m)<<'\n';
    }
    return 0;
}
/*
4
421 1
41212 2
4112 2
3241 2
*/