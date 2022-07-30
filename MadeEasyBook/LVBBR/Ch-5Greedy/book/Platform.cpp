#include<iostream>
#include<algorithm>
using namespace std;

void minPlatform(int *arr,int *dept,int n)
{
    sort(arr,arr+n);
    sort(dept,dept+n);
    int i = 1,j = 0,plat = 1, result = 1;
    while (i<n && j<n)
    {
        if(arr[i] <= dept[j])
        {
            i++;
            plat++;
        }
        else{
            j++;
            plat--;
        }
        result = max(result,plat);
    }
    cout<<"\nMinimum Platform required for having *NO* train to wait = "<<result<<'\n';
}

int main()
{
    int arr[]={840,850,800,1000,1400,1700};
    int dept[]={1100,1020,810,1030,1800,1900};  
    int n = 6;
    // Greedy sol
    minPlatform(arr,dept,n);
    return 0;
}