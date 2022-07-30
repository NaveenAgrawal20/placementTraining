#include<iostream>
using namespace std;

/*Find the single */
/* Xor gives 0 on same bit and 1 on different */
/*
| = Bitwise AND
& = Bitwise OR
^ = Bitwise XOR
*/
int findSingle(int arr[],int n){
    int single = 0;
    for(int i = 0;i<n;i++)
        single ^= arr[i];
    return single;
}

int main()
{
    int a[] =  {1, 2, 1};
    int n = sizeof(a)/sizeof(int);
    cout<<findSingle(a,n);
    return 0;
}