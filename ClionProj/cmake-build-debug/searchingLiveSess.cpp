#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int low,int high,int k)
{
    int mid = (high + low)/2;
    if(low > high)
        return mid+1+k;
    if(arr[mid+1] - arr[mid] < k)
        return solve(arr,mid+1,high,k);
    else
        return solve(arr,low,mid-1,k);
}

int findKthPositive(vector<int>& arr, int k) {
    int low = 0,high = arr.size() - 1;
    return solve(arr,low,high,k);
}
int arr[3][3];
int countNum(int mid,int rows)
{
    int count = 0;
    for(int i = 0;i<rows;i++)
    {
        int j = rows;
        if(arr[j][i] < mid)
            count += rows - i;


    }
}

int main()
{
    vector<int> v = {2,3,4,7,11};
    cout<<findKthPositive(v,5)<<endl;
    vector<int> v2 = {1,2,3,4};
    cout<<findKthPositive(v2,2)<<endl;
    return 0;
}