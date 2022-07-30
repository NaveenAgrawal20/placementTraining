#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> &p1,pair<int,int> &p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        map<int, vector<pair<int, int>> > mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x;
                cin>>x;
                mp[x].push_back({i,j});
            }
        }
        int ans = 0;
        for(auto it:mp)
        {
            vector<pair<int,int>> v = it.second;
            sort(v.begin(),v.end());
            int sum = 0;
            int vSize = v.size();
            for(int i = 0;i<vSize;++i)
                sum += v[i].first;
            for(int i = 0;i<vSize;++i)
            {
                sum -= v[i].first;
                ans += (sum) - (vSize-(i+1))*v[i].first;
            }
            // sorting y
            sort(v.begin(),v.end(),comp);
            sum = 0;
            for(int i = 0;i<vSize;++i)
                sum += v[i].second;

            for(int i = 0;i<vSize;++i)
            {
                sum -= v[i].second;
                ans += (sum) - (vSize-(i+1))*v[i].second;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

/*
input
3 4
1 1 2 2
2 1 1 2
2 2 1 1
output
76
*/