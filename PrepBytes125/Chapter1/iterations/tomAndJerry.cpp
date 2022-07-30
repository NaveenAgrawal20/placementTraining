#include<iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int t,j;
        j = 2;
        cin>>t;
        while(t%2 == 0){ // while even convert to odd
            t /= 2;
        }            
        cout<<(t-1)/2<<"\n";
    }
    return 0;
}