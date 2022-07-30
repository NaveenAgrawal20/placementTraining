#include<iostream>
using namespace std;
void chocolates(int arr[], int n)
{
    int min = arr[0];
    while(n--)
        min = min > arr[n]?arr[n]:min;
    cout<<min;
}
int main()
{
    int a[] =  {5, 9, 2, 6};
    int n = sizeof(a)/sizeof(int);
    chocolates(a,n);
    return 0;
}
