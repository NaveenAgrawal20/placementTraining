#include<iostream>
using namespace std;
/*
Find ...tens,once
*/
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        long long digits = 0;
        cin>>n;
        for(int i = 1;i<=n;i*=10)
            digits += n - i + 1;
        cout<<digits<<"\n";
    }
}