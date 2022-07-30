#include<iostream>
using namespace std;

/*
Simply do LCM on number and add those number for eg: 6 = 2,3 and sum of lcm is 2+3 = 5.
*/
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, i;
        int sum = 0;
        cin>>n;
        if(n == 1)
            cout<<1<<"\n";    
        i = 2;
        while(n != 1){
            if(n%i == 0){
                sum += i;
                n = n /i;
            }
            else
                i++;
        }
        cout<<sum<<"\n";
    }
}