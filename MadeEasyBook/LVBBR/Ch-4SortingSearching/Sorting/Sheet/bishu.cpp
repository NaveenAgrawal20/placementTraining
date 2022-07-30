#include<iostream>
#include<algorithm>
#define xag ios_
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 2;
    while(t--)
    
    {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;++i)
        cin>>a[i];

    sort(a,a+n);
    // Sum array cumulative
    int sum[n];
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i-1]+a[i];
    

    int q;
    cin>>q;
    while(q--)
    {
        int power;
        cin>>power;
        int x = upper_bound(a,a+n,power) - a;
        cout<<x<<' ';
        if(x <= 0)
            cout<<0<<'\n';
        else
            cout<<sum[x-1]<<'\n';
    }
}
    return 0;
}

/*
7
1 2 3 4 5 6 7
3
3
10
2

5
5 6 7 8 9
7
9
1
4
5
6
7
8

*/