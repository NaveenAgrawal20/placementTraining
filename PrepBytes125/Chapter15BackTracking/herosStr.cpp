#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, t;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> t;
    sort(a, a + n);
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int l = j+1;
            int r = n-1;
            while(l < r){
                int sum  = a[i] + a[j]+a[l]+a[r];
                if(sum == t){
                    vector<int> v;
                    v.push_back(a[i]);
                    v.push_back(a[j]);
                    v.push_back(a[l]);
                    v.push_back(a[r]);
                    res.push_back(v);
                }
                if(sum > t){
                    do{
                        --r;
                    }while(a[r] == a[r+1] && r > l);
                }else{
                    do{
                        l++;
                    }while(a[l] == a[l-1] && r > l);
                }
            }
            while(a[j] == a[j+1] && j < n - 1)
                j++;
        }
        while(a[i] == a[i+1] && i < n - 1)
            i++;
    }
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
/*
6
1 0 -1 0 -2 2
0
*/
