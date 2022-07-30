#include<iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(i = 0;i<n;i++)
            cin>>a[i];
        int min = 0,max = 0;
        for(i = 0;i<n;i++){
            if(a[i] < a[min])
                min = i;
            if(a[i] > a[max])
                max = i;
        }
        cout<<a[min]<<" "<<a[max]<<"\n";
    }
    
    return 0;
}
/*
2
5
4 3 2 1
7
7 2 8 4 3 9 1
*/