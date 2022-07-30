#include <iostream>
#include <algorithm>
using namespace std;
void swap(int &a,int &b){int temp = a;a = b;b = temp;}

int findMedian(int *a,int siz){
    sort(a,a+siz);
    return a[siz/2];
}
int partition(int *a,int low,int high,int x){
    // Search for x in arr[l..r] and move it to end
    int i;
    for( i = low;i<high;++i) {
        if (a[i] == x)
            break;
    }
    swap(a[i],a[high]);

    // Standard Partition algo
    i = low;
    for(int j = low;j<= high-1;++j){
        if(a[j] <= x){
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[high],a[i]);
    return i;
}

int quickSelect(int *a,int low,int high,int k){
    // If k is smaller than number of elements in array
    if (k > 0 && k <= high - low + 1)
    {
        int n = high - low + 1; // num of ele in a[l...r]
        /*Divide arr[] in groups of size 5, calculate median
        of every group and store it in median[] array.*/
        int median[(n+4)/5]; // Num of groups ceil(n/5)
        int i;
        for(i = 0;i<n/5;++i){
            median[i] = findMedian(a+low+i*5,5);
        }
        if(i*5<n) // For last group with less than 5 elements
        {
            median[i] = findMedian(a+low+i*5,n%5);
            i++;
        }
        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed = (i == 1)?median[i-1]:
                        quickSelect(median,0,i-1,i/2);
        int pivot = partition(a,low,high,medOfMed);
        // If position is same as k
        if(k - 1  == pivot-low) // index from 0
            return a[pivot];
        else if(k - 1 < pivot - low)
            return quickSelect(a,low,pivot - 1,k);
        else
            return quickSelect(a,pivot+1,high,k-1-(pivot-low));
    }
    return INT_MAX;
}




int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3,n = 6;
    cout<<quickSelect(arr,0,n-1,k)<<'\n';
    // 7

    int  arr2[] = {7, 10, 4, 3, 20, 15};
    k = 4;
    cout<<quickSelect(arr2,0,n-1,k)<<"\n";
    return 0;}