#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void backtracking(int a[],int i,int n)
{
    if(i==n-1)
    {
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return;
    }

    for(int k=i;k<n;k++)
    {
    swap(&a[k],&a[i]);
    backtracking(a,i+1,n);

    swap(&a[k],&a[i]);


    }

}

int main()
{
    int n;
    cin>>n;
    int a[n],ans[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    backtracking(a,0,n);


    return 0;
}
/*
Take one value of the array at a time and fix it at the first position. (use swap to put every character at the first position)
Make a recursive call to the rest of the values in the array.
Use swap to revert the values back to its original form for next iteration.
Draw a recursion tree first and see how it actually works.
Think about base Condition.
Print the output in correct order.
*/