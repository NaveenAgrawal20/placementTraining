#include <iostream>
#include <string>

using namespace std;
//Problem-3 Generate all the strings of n bits. Assume A[0..n – 1] is an array of size n.
void display(int *a,int n){
    for(int i = 0;i<n;i++)
        printf("%d",a[i]);
    cout<<endl;
}
void binaryStr(int *a, int i,int n) {
    if(i<1)
    {
        display(a,n);
        return ;
    }
    a[n-i] = 0;
    binaryStr(a,i-1,n);
    a[n-i] = 1;
    binaryStr(a,i-1,n);
}

int main() {
    int n = 3;
    int *a = new int[n];
    binaryStr(a, n,n);
    return 0;
}
/*
000
001
010
011
100
101
110
111
 */