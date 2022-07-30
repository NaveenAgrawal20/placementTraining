#include <bits/stdc++.h>
using namespace std;
 
// Function to find the sum
// of sum of all the subset
int sumOfSubset(int a[], int n)
{
    int times = pow(2, n - 1);
 
    int sum = 0;
 
    for (int i = 0; i < n; i++) {
        sum = sum + (a[i] * times);
    }
 
    return sum;
}
 
// Driver Code
int main()
{
    int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout<<sumOfSubset(a, n)<<endl;
}