#include<bits/stdc++.h>

using namespace std;

int dp[505][2005];

int solve(vector<int> &words,int len, int i, int rem)
{
    // last word
    if(i == words.size() )
    {
        return 0;
    }
    if(dp[i][rem] != -1)
        return dp[i][rem];

    int ans;
    // cant fit
    if(words[i] > rem)
        ans = (rem+1)*(rem+1) + solve(words,len,i+1,len-words[i]-1);
    else
    {
        // next line
        int count1 = (rem+1)*(rem+1) + solve(words,len,i+1,len-words[i]-1);
        int count2 = solve(words,len,i+1,rem-words[i]-1);
        ans = min(count1,count2);
    }
    dp[i][rem] = ans;
    return dp[i][rem];
}

int solveWordWrap(vector<int> &arr, int k)
{
    memset(dp, -1, sizeof(dp));
    return solve(arr,k,0,k);
}

int main()
{
    vector<int> words = {3, 2, 2, 5};
    int k = 6;
    cout << solveWordWrap(words, k);
    return 0;
}