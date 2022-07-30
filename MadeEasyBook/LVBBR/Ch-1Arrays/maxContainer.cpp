#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> h)
{
    int n = h.size();
    int lmax = 0,rmax = 0,res = 0,l = 0,r=n-1;
    while(l<=r)
    {
        if(h[l] >= h[r])
        {
            rmax = max(rmax,h[r]);
            res = max(res,(r-l)*rmax);
            r--;
        }
        else{
            lmax = max(lmax,h[l]);
            res = max(res,(r-l)*lmax);
            l++;
        }
    }
    return res;
}

int main()
{
    vector<int> h1 = {1,8,6,2,5,4,8,3,7};
    vector<int> h2 = {1,1};
    cout<<solve(h1)<<endl;
    cout<<solve(h2)<<endl;
    return 0;
}