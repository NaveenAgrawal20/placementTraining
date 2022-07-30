#include<iostream>
using namespace std;

void printArr(int *a,int n){
    for(int i = 0;i<n;++i)
        cout<<a[i]<<' ';
    cout<<'\n';
}

int main()
{
    const int n = 7;
    int a[n] = {1, 4, 1, 2, 7, 5, 2};
    int b[n],c[10] = {0};
    int i;
    for(i = 0;i<n;++i)
        c[a[i]] = c[a[i]] + 1;
    for(i = 1;i<10;i++)
        c[i] = c[i]+c[i-1];
    
    for(i = 0;i<n;i++)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
    printArr(a,7);
    cout<<"Sorted\n";
    printArr(b,7);
    
    return 0;
}