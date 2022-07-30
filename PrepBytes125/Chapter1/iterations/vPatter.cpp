#include<iostream>
using namespace std;

int main()
{
    char c;
    cin>>c;
    for(int i = 1;i<=5;i++){
        for(int j = 1;j<=i;j++){
            cout<<j;
        }
        for(int k = 1;k<=2*(5 - i);k++){
            cout<<" ";
        }
        for(int j = i;j>=1;j--){
            cout<<j;
        }
        cout<<"\n";
    }
    return 0;
}