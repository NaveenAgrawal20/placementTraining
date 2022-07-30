#include<iostream>
#include<algorithm>
using namespace std;
/* Problem-9 Let A and B be two arrays of n elements each. Given a number K, give an
O(nlogn) time algorithm for determining whether there exists a ∈ A and b ∈ B such that a
+ b = K. */
bool find(int *a,int *b,int n,int k)
{
    sort(a,a+n);
    for(int i = 0;i<n;i++){
        int c = k - b[i];
        if(binary_search(a,a+n,c))
            return true;
    }
    return false;
}

int main()
{
    int a[] = {12,1,2,51,6,4,9,1};
    int b[] = {11,14,21,6,11,2,12,4,5};
    int n = sizeof(b)/sizeof(int);
    cout<<find(a,b,n,23)<<endl;
    
    return 0;
}