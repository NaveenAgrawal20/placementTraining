#include <iostream>
#include <algorithm>
using namespace std;
 
// Function to find greater elements
void findMaxElements(
    int arr1[], int arr2[], int n)
{
    // Index counter for arr1
    int cnt1 = 0;
    // Index counter for arr2
    int cnt2 = 0;
    // To store the maximum elements
    int maxelements = 0;
 
    while (cnt1 < n && cnt2 < n) {
 
        // If element is greater,
        // update maxelements and counters
        // for both the arrays
        if (arr1[cnt1] > arr2[cnt2]) {
            maxelements++;
            cnt1++;
            cnt2++;
        }
        else {
            cnt1++;
        }
    }
 
    // Print the maximum elements
    cout << maxelements << endl;
}
 
int main()
{
    int n;
        cin >> n;
        int *a = new int[n];
        int *b = new int[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
         sort(a,a+n);
        sort(b,b+n);
    findMaxElements(a, b, n);
 
    return 0;
}