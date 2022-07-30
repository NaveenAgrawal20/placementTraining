#include<iostream>
using namespace std;

int stair(int n){
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    return stair(n-1)+stair(n-2);
}

int main()
{
    // int a[]  = {10,-20,35,40,10,-10,100,-50};
    // int n = sizeof(a)/sizeof(int);
    
    // int M[n] = {0};
    // if(a[0] > 0)
    //     M[0] = a[0];
    // M[0] = 0;
    // for(int i = 1;i<n;i++){
    //     if(M[i-1] + a[i] > 0)
    //         M[i] = M[i-1] + a[i];
    // }
    // int max = 0;
    // for(int i:M){
    //     if(i > max)
    //         max = i;
    // }
    // cout<<max<<"\n";
    cout<<stair(1)<<endl;
    cout<<stair(2)<<endl;
    cout<<stair(3)<<endl;
    cout<<stair(4)<<endl;
    cout<<stair(5)<<endl;
    return 0;
}