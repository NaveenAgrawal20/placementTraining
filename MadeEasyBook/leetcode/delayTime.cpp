#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<pair<int,int>> adj[101];
public:
    void Dijkstra(vector<int>& recieveTime, int n, int source)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,source}); // Received_time, source 
        recieveTime[source] = 0;

        while(!pq.empty())
        {
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if(recieveTime[currNode] < currNodeTime) // it means we have traversed it
                continue;

            for(pair<int,int> edge:adj[currNode])
            {
                int time = edge.first;
                int dest = edge.second;
                if(recieveTime[dest] > time+currNodeTime)
                {
                    recieveTime[dest] = time+currNodeTime;
                    pq.push({recieveTime[dest], dest});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Building Adjacency list
        for(vector<int> time:times)
        {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];

            adj[source].push_back({travelTime,dest});
        }

        vector<int> recieveTime(n+1,INT_MAX);
        Dijkstra(recieveTime,n,k);

        int ans = INT_MIN;
        // max in recieveTime is total time
        for(int time:recieveTime)

            ans = min(ans,time);
        int ans2 = ans;
        return ans == INT_MIN?-1:ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> times  = {{2,1,1},{2,3,1},{3,4,1}};
    cout<<s.networkDelayTime(times,4,2)<<'\n';
}