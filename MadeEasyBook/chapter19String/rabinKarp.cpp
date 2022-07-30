#include<iostream>
#include<math.h>
#include<string>
#include<cstring>
using namespace std;

bool isStrMatch(string t,string pattern,int s,int m){
    for(int i = 0;i<m;i++){
        if(pattern[i] != t[s+i])
            return false;
    }
    return true;
}

void rabin_karp_algo(string text,string pattern,int d,int q){
    int n = text.length();
    int m = pattern.length();
    int h = ((int)pow(d,m-1))%q;
    int p = 0; // hassh value of pattern
    int t[n-m+1]; // hash value of each m characters of text
    memset(t,0,sizeof(t));

    for (int i = 0; i < m; i++)
    {
        p = (d*p+(pattern[i]-'a'))%q;
        t[0] = (d*t[0] + (text[i]-'a'))%q;
    }
    for(int s = 0;s<n-m+1;s++){
        if(p==t[s]){
            if(isStrMatch(text,pattern,s,m)){
                cout<<"Pattern matches after "<<s<<" shifts\n";
            }
        }
        if(s<n-m){
            t[s+1] = ((d*(t[s]-(text[s]-'a')*h))+text[s+m]-'a')%q;
        }
    }

}

int main()
{
    string text,pattern;
    cin>>text>>pattern;
    int d = 26; // for alphabets(eng)
    int q = 1000000007;
    rabin_karp_algo(text,pattern,d,q);
    cout<<"Program finished\n";
    return 0;
}
/*
aabxcadaabx
aabx
aabaabaaabaababa
aba
bcefcadea
dea
*/