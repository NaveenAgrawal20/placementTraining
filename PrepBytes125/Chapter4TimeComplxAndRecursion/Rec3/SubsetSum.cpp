// #include <iostream>
// #include <math.h>
// #define MAX 10
// #define endl "\n"
// using namespace std;
// // Discrete Mathematics
// int fact[MAX];

// int binomialTerm(int n, int r)
// {
// 	return (fact[n] / fact[r]) / fact[n - r];
// }
// int getSum(int *a, int n)
// {
//     fact[0] = 1;
//     for (int i = 0; i < n; i++)
//         fact[i] = i * fact[i - 1];

//     int mul = 0;
//     for (int i = 0; i < n - 1; i++)
//     {
//         mul += (int)pow(2, i) * binomialTerm(n - 1, i);
//     }
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//         sum += mul * a[i];

//     return sum;
// }

#include <bits/stdc++.h>
using namespace std;
#define maxN 10
 
// To store factorial values
int fact[maxN];
 
// Function to return ncr
int ncr(int n, int r)
{
    return (fact[n] / fact[r]) / fact[n - r];
}
 
// Function to return the required sum
int findSum(int* arr, int n)
{
    // Intialising factorial
    fact[0] = 1;
    for (int i = 1; i < n; i++)
        fact[i] = i * fact[i - 1];
 
    // Multiplier
    int mul = 0;
 
    // Finding the value of multipler
    // according to the formula
    for (int i = 0; i <= n - 1; i++)
        mul += (int)pow(2, i) * ncr(n - 1, i);
 
    // To store the final answer
    int ans = 0;
 
    // Calculate the final answer
    for (int i = 0; i < n; i++)
        ans += mul * arr[i];
 
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout<<findSum(a, n)<<endl;
    }
    return 0;
}
/*
1
8
2 4 1 3 6 3 2 6
2 4 1 3 6 
*/
