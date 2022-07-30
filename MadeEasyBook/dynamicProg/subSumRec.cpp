#include <iostream>
using namespace std;
#define MAX 1000
// O(2^n)
int subSetSum(int arr[],int n,int sum){
    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;
    if(arr[n-1] > sum)
        return subSetSum(arr,n-1,sum);
    return subSetSum(arr,n-1,sum-arr[n-1]) || subSetSum(arr,n-1,sum);
}

// DP -> memoization
int subSumMem(int arr[],int n,int sum,int mem[][MAX]){
    if(sum == 0)
        return 1;
    if(n == 0)
        return 0;
    if(mem[n][sum] != 0)
        return mem[n][sum];
    if(arr[n-1] > sum)
        mem[n][sum] = subSumMem(arr,n-1,sum,mem);
    else
        mem[n][sum] = subSetSum(arr,n-1,sum-arr[n-1]) || subSetSum(arr,n-1,sum);
    return mem[n][sum];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,sum;
        cin>>n>>sum;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        int mem[n+1][MAX];
        for(int i = 0;i<n+1;i++){
            for (int j = 0; j < sum + 1; ++j) {
                mem[i][j] = 0;
            }
        }
//        if(subSetSum(arr,n,sum)){
        if(subSumMem(arr,n,sum,mem)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }

    }
    return 0;
}
/*
5
4 12
2 6 14 6
4 81
2 6 12 6
3 4
1 2 3
5 12
6 9 1 3 5
5 6
1 1 1 1 1
 */