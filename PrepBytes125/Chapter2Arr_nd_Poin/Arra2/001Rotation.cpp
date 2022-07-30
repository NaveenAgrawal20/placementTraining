#include<iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,k,i;
        cin>>n>>k;
        int a[n];
        for(i = 0;i<n;i++)
            cin >> a[i];
        while (k >= n)
        {
            k = k % n;
        }
        int t[k];
        // saving into array
        for(i = k;i>=1;i--)
            t[k - i] = a[n - i];
        // from reverse
        for(i = n - 1;i>=k;i--)
            a[i] = a[i-k];
        // copying t into a
        for(i = 0;i<k;i++)
            a[i] = t[i];
        //printing a
        for(i = 0;i<n;i++)
            cout<<a[i]<<" ";
    }
    return 0;
}
/*
1
5 2 
1 2 3 4 5
*/