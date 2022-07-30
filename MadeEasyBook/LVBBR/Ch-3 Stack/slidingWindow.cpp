#include<bits/stdc++.h>
using namespace std;

vector<int> slidingMaximum(int *arr,int k, int n)
{
	// Using next greater ele logic 
	// but here we will save index
	// step1: find nge
	vector<int> nge(n,0);
	nge[n-1] = n;

	stack<int> st;
	st.push(n-1);
	for(int i = n-2;i >= 0;--i)
	{
		while(!st.empty() && arr[st.top()] <= arr[i])
			st.pop();
		if(st.empty())
			nge[i] = n;
		else
			nge[i] = st.top();
		st.push(i);
	}
	// for(auto e:nge) cout<<e<<' ';
	
	// step 2: getting ans for sliding window
	vector<int> ans(n-k+1);
	for(int i = 0;i<=n-k;++i)
	{
		int j = i;
		while(nge[j] < i+k)
			j = nge[j];
		ans[i] = arr[j];
	}
	return ans; 
}

int main()
{
	int arr[] = { 8, 5, 10, 7, 9, 4, 15, 12, 90, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    vector<int> ans=slidingMaximum(arr,k,n);
      for(auto x:ans) cout<<x<<" ";
    return 0;
}