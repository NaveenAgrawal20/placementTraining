#include<iostream>
#include<algorithm>
using namespace std;


int partition(int *a,int low,int high){
    int pivot = a[low];
    int i , j = low;
    for(i = low+1;i<=high;++i){
        if(a[i] < pivot){
            j++;
            swap(a[i],a[j]);
        }
    }

    swap(a[j],pivot);
    return j;
}

int quickSelect(int *a,int low,int high,int k){
    if(low == high)
        return a[low];
    int pivot = partition(a,low,high);
    if(k == pivot){
        return a[pivot];
    }
    else if(k < pivot){
        return quickSelect(a,low,pivot-1,k);
    }else{
        return quickSelect(a,pivot+1,high,k);
    }
}


int main(){
    int arr[] = {0,7, 10, 4, 3, 20, 15};
    int k = 3,n = 6;
    cout<<quickSelect(arr,1,n,k)<<'\n';
    // 7

    int  arr2[] = {0,7, 10, 4, 3, 20, 15};
    k = 4;
    cout<<quickSelect(arr2,1,n,k)<<"\n";
    return 0;
}
