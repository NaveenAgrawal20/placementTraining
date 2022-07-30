#include<iostream>
using namespace std;

int main()
{
    int b,c,t,count = 0;
    cin>>b;
    while(b--)
    {
        cin>>t>>c;
        if(c - t >= 2)
            count++;    
    }
    cout<<count<<"\n";
    return 0;
}