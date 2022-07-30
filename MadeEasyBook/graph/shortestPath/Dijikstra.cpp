#include<iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> iPair;

void addAdj(vector<pair<int,int>> *adj,int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
}

void dijkstra(vector<pair<int,int>> *adj,int n,int s){
    int distance[n],path[n];
    int status[n],PERM = 1,TEMP = 0; // to limit dijkstra for only +ve weight (vertices only 1 time visit)
    for (int i = 0; i < n; ++i) {
        status[i] = TEMP;
        distance[i] = INT_MAX;
    }
    priority_queue<iPair,vector<iPair>,greater<>> pq;

    distance[s] = 0;
    pq.push(make_pair(0,s)); // here 0 is distance // we prioritize on basis of difference

    while(!pq.empty()){
        int u = pq.top().second;pq.pop();
        status[u] = PERM;
        for(pair<int,int> ele:adj[u]){
            int v  = ele.first;
            int wt = ele.second;
            if(status[v] == TEMP && distance[v] > distance[u]+wt){
                distance[v] = distance[u]+wt;
                path[ele.first] = u;
                pq.push(make_pair(distance[v],v));
            }
        }
    }

    // printing distance;
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, distance[i]);

    // printing path (as predecessor in deeplic)
    cout<<"\nPath is \n";
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, path[i]);
}

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0)
            return -1;
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n,INT_MAX));
        vector<pair<int,int>> dir = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({1,0,0}); // distance, source, destination
        dis[0][0] = 1;

        while(!pq.empty())
        {
            int nodeDis = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();

            for(int i = 0;i<8;++i)
            {
                int newRow = row+dir[i].first;
                int newCol = col+dir[i].second;
                if(newRow >= 0 && newRow<n && newCol >= 0 && newCol < n  && grid[newRow][newCol] == 0)
                {
                    int newDis = nodeDis + 1;
                    if(newDis < dis[newRow][newCol])
                    {
                        dis[newRow][newCol] = newDis;
                        pq.push({newDis,newRow,newCol});
                    }
                }
            }
        }
        return dis[n-1][n-1] == INT_MAX?-1:dis[n-1][n-1];
    }

int main() {
//    int n,numV;
//    cin>>n>>numV;
//    vector<pair<int,int>> *adj;
//    adj = new vector<pair<int,int>>[numV];
//    for(int i = 0;i<n;i++){
//        int u,v,w;
//        cin>>u>>v>>w;
//        addAdj(adj,u,v,w);
//    }
//    dijkstra(adj,numV,0);
    vector<vector<int>> grid = {{0,1},{1,0}};
    cout<<shortestPathBinaryMatrix(grid)<<'\n';
    return 0;
}
/*
14 9
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

6 5
0 1 4
0 2 1
1 4 4
2 1 2
2 3 4
3 4 4
 */