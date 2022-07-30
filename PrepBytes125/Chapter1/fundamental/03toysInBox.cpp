#include<iostream>
using namespace std;

int main()
{
    int n,t,c,availableBoxes = 0;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>t>>c;
        if(c-t >= 2)
            availableBoxes++;
    }
    cout<<availableBoxes;
    return 0;
}