#include<iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,sum = 1;
        cin>>n;
        for(int i = 2;i<=n/2;i++){
            if(n%i == 0)
                sum += i;
        }
        if(n != 1 && sum == n)
            cout<<"true"<<"\n";
        else
            cout<<"false"<<"\n";
    }
    return 0;
}