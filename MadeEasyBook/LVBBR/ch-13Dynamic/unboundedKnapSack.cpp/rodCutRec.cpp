#include<iostream>
using namespace std;

int lenArr[30],price[30];


int solveRod(int len,int n)
{
    if(n == 0 || len == 0)
        return 0;
    if(lenArr[n-1] <= len)
        return max(solveRod(len,n-1), price[n-1]+solveRod(len-lenArr[n-1],n));
    else
        return solveRod(len,n-1);
}

int solveRod_1D(int len,int n)
{
    // int dp[n+1][len+1];
    int dp[len+1] = {0};
    for(int i = 1;i<=len;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(lenArr[j] <= i)
                dp[i] = max(dp[i],price[j] + dp[i-lenArr[j]]);
        }
    }
    return dp[len];
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
        cin>>lenArr[i];
    for(int i = 0;i<n;i++)
        cin>>price[i];
    cout<<solveRod(n,n)<<'\n';
    cout<<solveRod_1D(n,n)<<'\n';
    return 0;
}
/*
8
1 2 3 4 5 6 7 8
1   5   8   9  10  17  17  20

8
1   2   3   4   5   6   7   8 
3   5   8   9  10  17  17  20
*/