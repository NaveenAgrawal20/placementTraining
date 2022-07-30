#include<bits/stdc++.h>
#include<vector>
using namespace std;

void addAdj(vector<pair<int,int>> *adj,int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
}

void dijkstra(vector<pair<int,int>> *adj,int n,int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,s});

    bool visited[n];
    int distance[n];

    for(int i = 0;i<n;++i)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[s] = 0;

    while(!pq.empty())
    {
        int top = pq.top().first;
        int dis = pq.top().second;
        pq.pop();
        if(visited[top] == true)
            continue;

        visited[top] = true;
        
        for(pair<int,int> edge:adj[top])
        {
            int v = edge.first;
            int wt = edge.second;
            if(visited[v] == false && distance[v] > distance[top] + wt)
            {
                distance[v] = distance[top] + wt;
                pq.push({distance[v],v});
            }
        }
    }
    // printing distance;
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, distance[i]);
}

int main()
{
    int n, numV;
    cin >> n >> numV;
    vector<pair<int, int>> *adj;
    adj = new vector<pair<int, int>>[numV];
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addAdj(adj, u, v, w);
    }
    dijkstra(adj, numV, 0);
    return 0;
}