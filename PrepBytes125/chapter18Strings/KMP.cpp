#include<iostream>
using namespace std;

void compute_prefix(string p,int *lps,int m){
    int k = 0;
    for(int q = 1;q<m;++q){
        while(k > 0 && p[k] != p[q])
            k = lps[k-1];
        if(p[k] == p[q])
            k++;
        lps[q] = k;
    }
}

void kmp_algo(string t,string p){
    int n = t.length();
    int m = p.length();
    int lps[m] = {0};
    compute_prefix(p,lps,m);
    int q = 0;
    for(int i = 0;i<n;i++){
        while(q > 0 && p[q] != t[i])
            q = lps[q-1];
        if(p[q] == t[i])
            q++;
        if(q == m){
            cout<<"Pattern matches at index = "<<(i-m+1)<<"\n";
            q = lps[q-1];
        }
    }
}

int main()
{
    string text,p;
    cin>>text>>p;
    kmp_algo(text,p);
    return 0;
}
/*
ABABDABACDABABCABAB
ABABCABAB

aaabababsabcacascafsaba
aba

aababaababaaabaabaaabaabababaa
aabaabab
*/