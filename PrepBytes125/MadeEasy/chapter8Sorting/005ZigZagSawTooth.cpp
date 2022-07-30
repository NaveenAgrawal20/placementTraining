#include<iostream>
using namespace std;
/*  DISTINCT elements rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f*/
void display(int *a,int n)
{
    for(int i = 0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
int main()
{
    // int a[] = {4, 3, 7, 8, 6, 2, 1};
    // int a[] = {1, 4, 3, 2} ;
    // int n = sizeof(a)/sizeof(int);
    int n = 33;
    int a[33];
    for(int i = 0;i<33;i++)
        cin>>a[i];

    for(int i = 1;i<n;i+=2)
    {
        if(i > 0 && a[i - 1] > a[i])
            swap(a[i],a[i-1]);
        if(i < n-1 && a[i+1] > a[i])
            swap(a[i],a[i+1]);
    }
    display(a,n);
    return 0;
}