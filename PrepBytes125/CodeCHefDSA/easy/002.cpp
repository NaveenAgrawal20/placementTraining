// CPP to find min cost to make
// XOR of whole array zero
#include <bits/stdc++.h>
using namespace std;

// function to find min cost
void minCost(int arr[], int n)
{
	int cost = INT_MAX;
	int element;

	// calculate XOR sum of array
	int XOR = 0;
	for (int i = 0; i < n; i++)
		XOR ^= arr[i];

	// find the min cost and element corresponding
	for (int i = 0; i < n; i++) {
		if (cost > abs((XOR ^ arr[i]) - arr[i])) {
			cost = abs((XOR ^ arr[i]) - arr[i]);
			element = arr[i];
		}
	}

	cout << "Element = " << element << endl;
	cout << "Operation required = " << abs(cost);
}

// driver program
int main()
{
    int n;
	cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
	minCost(arr, n);
	return 0;
}
