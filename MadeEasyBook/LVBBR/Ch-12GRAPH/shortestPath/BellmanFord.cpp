#include<iostream>
#include <vector>
#include <queue>

using namespace std;

void addAdj(vector<pair<int, int>> *adj, int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
}

void bellmanFord(vector<pair<int, int>> *adj, int n, int s) {
    int distance[n], path[n];
//    bool isPresentinQueue[n];
    queue<int> q;


    for (int i = 0; i < n; i++) {
//        isPresentinQueue[i] = false;
        distance[i] = INT_MAX;
    }

    distance[s] = 0;
    q.push(s);
//    isPresentinQueue[s] = true;

    int k = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if(s == u)
            ++k;
        if(k > n)
        {
            cout<<"NEGATIVE CYCLE\n";
            return;
        }

        for (pair<int, int> ele:adj[u]) {
            int v  = ele.first;
            int wt = ele.second;
            if(distance[v] > distance[u]+wt){
                distance[v] = distance[u] + wt;
                path[v] = u;
                q.push(v);
            }
        }
    }

    // printing distance;
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, distance[i]);

    // printing path (as predecssor in deeplic)
    cout << "\nPath is \n";
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, path[i]);

    // path printer
    int des;
    cout<<"Enter dest ";
    cin>>des;
    vector<int> pathStr;
    while(des != s){
        pathStr.push_back(des);
        des = path[des];
    }
    pathStr.push_back(s);
    vector<int>::reverse_iterator it = pathStr.rbegin();
    for(;it != pathStr.rend() ;it++){
        cout<<*it<<" ";
    }
}


int main() {
    int n, numV;
    cin >> n >> numV;
    vector<pair<int, int>> *adj;
    adj = new vector<pair<int, int>>[numV];
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addAdj(adj, u, v, w);
    }
    bellmanFord(adj, numV, 0);
    return 0;
}

/*
16 8
0 1 8
0 2 9
0 4 7
1 5 9
2 0 5
2 1 -4
2 3 3
3 1 3
3 2 6
3 5 4
4 7 16
5 0 4
5 6 -8
5 7 5
6 3 5
6 7 2

-ve cycle
6 5
0 1 2
0 2 7
1 3 -9
2 4 6
3 0 4
3 4 5


GFG
8 5
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
 */
