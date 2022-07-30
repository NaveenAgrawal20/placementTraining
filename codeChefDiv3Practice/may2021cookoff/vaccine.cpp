#include<iostream>
#define MAX 11
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int g,p,x[MAX],sum = 0;
        cin>>g>>p;
        for(int i = 1;i<MAX;i++)
            cin>>x[i];
        
        int maxsum = x[MAX-1];
        for(int i = MAX - 2;i >= g;i--)
            maxsum += x[i];
        
        // if((maxsum - x[g]) % p != 0 && maxsum > p)
        //     sum = maxsum - maxsum
        // else
        //     sum = maxsum;
        cout<<(maxsum/p + 1)<<" "<<(maxsum/p + maxsum%p)<<"\n";

    }
    return 0;
}
/*
6
5 2 2 2 2 2 2 2 2 2 2 2
5 2 2 2 2 2 2 3 2 2 2 2
9 4 2 2 2 2 3 2 2 2 2 2
5 2 2 2 2 2 4 5 2 2 2 2
5 3 2 2 2 2 2 2 2 2 2 2
10 1 2 2 2 2 2 2 2 2 2 2
*/