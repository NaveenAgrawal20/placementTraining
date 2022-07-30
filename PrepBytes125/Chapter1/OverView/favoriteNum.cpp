#include<iostream>
using namespace std;

int main()
{
    int t,n,rem,count;
    cin>>t;
    while(t--){
        cin>>n;
        while(n){
            rem = n%10;
            n/=10;
            if(rem == 5)
                count++;
            cout<<count<<"\n";    
        }
    }
    return 0;
}