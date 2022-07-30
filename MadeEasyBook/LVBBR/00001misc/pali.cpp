#include<iostream>
using namespace std;

bool solve(string s)
{
    int n = s.length();
    int j = n-1;
    for(int i = 0;i<j;j--,i++)
    {
        if(s[i] != s[j])
            return false;
    }
    return true;
}

int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fib(n-1)+fib(n-2);
}

int main()
{
    string s;
    int n;
    cin>>n;
    // cin>>s;

    // cout<<solve(s)<<'\n';
    for(int i = 1;i<=n;i++)
        cout<<fib(i)<<'\n';
    return 0;
}