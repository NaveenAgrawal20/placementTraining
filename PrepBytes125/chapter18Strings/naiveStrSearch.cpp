#include<iostream>
#include<string>
using namespace std;

bool isStrMatch(string t,string pattern,int s,int m){
    for(int i = 0;i<m;i++){
        if(pattern[i] != t[s+i])
            return false;
    }
    return true;
}

void naiveStringMatch(string t,string s){
    int n = t.length();
    int m = s.length();
    for (int i = 0; i < n; i++)
    {
        if(isStrMatch(t,s,i,m)){
            cout<<"Pattern matches after "<<i<<" shifts\n";
        }
    }
    
}

int main()
{
    string t,p;
    cin>>t>>p;
    naiveStringMatch(t,p);
    cout<<"Program finished\n";return 0;
}
/*
aabxcadaabx
aabx
*/