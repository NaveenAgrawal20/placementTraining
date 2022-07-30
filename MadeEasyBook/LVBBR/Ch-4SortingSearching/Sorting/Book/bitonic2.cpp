#include <iostream>
using namespace std;

int binSearch(int *a,int l, int h, int k)
{
    int mid = l + (h - l)/2;
    if(l > h)
        return -1;
    if(a[mid] == k)
        return mid;
    if(a[l] <= a[mid]) // 1st sorted half
    {
        if(k >= a[l] && k < a[mid])
            return binSearch(a,l,mid-1,k);
        else
            return binSearch(a,mid+1,h,k);
    }else{
        if(k > a[mid] && k <= a[h])
            return binSearch(a,mid+1,h,k);
        else 
            return binSearch(a,l,mid-1,k);
    }
}

int main()
{
    int k = 5;
    int a[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    // int a[] = {4,3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Found at index " << binSearch(a, 0, n-1, k) << '\n';
    cout << "Found at index " << binSearch(a, 0, n-1, 16) << '\n';
    cout << "Found at index " << binSearch(a, 0, n-1, 14) << '\n';
    cout << "Found at index " << binSearch(a, 0, n-1, 15) << '\n';
    cout << "Found at index " << binSearch(a, 0, n-1, 25) << '\n';
    cout << "Found at index " << binSearch(a, 0, n-1, 20) << '\n';
    return 0;
}