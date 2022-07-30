#include<iostream>
#define endl "\n"
using namespace std;

int solve(int a[],int low,int high)
{
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(a[mid] == 1)
        {
            if(a[mid-1] != 0 && mid != 0)
                high = mid - 1;
            else
                return mid;
        }
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin>> n;
        int *a = new int[n];
        for(int i = 0;i<n;i++){
            cin >> a[i];
        }
        int ans = solve(a,0,n-1);
        cout<<ans<<endl;
    }
    return 0;
}