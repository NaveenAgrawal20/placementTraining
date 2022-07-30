#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> iPair;

void addAdj(vector<pair<int, int>> *adj, int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
}

void dijkstra(vector<pair<int, int>> *adj, int n, int s, int e) {
    int distance[n], path[n];
    int status[n], PERM = 1, TEMP = 0;
    for (int i = 0; i < n; ++i) {
        status[i] = TEMP;
        distance[i] = INT_MAX;
    }
    priority_queue<iPair, vector<iPair>, greater<>> pq;

    distance[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        status[u] = PERM;
        for (pair<int, int> ele:adj[u]) {
            int v = ele.first;
            int wt = ele.second;
            if (status[v] == TEMP && distance[v] > distance[u] + wt) {
                distance[v] = distance[u] + wt;
                path[ele.first] = u;
                pq.push(make_pair(distance[v], v));
            }
        }
    }
    if(distance[e] == INT_MAX)
        cout<<"-1"<<'\n';
    else
        cout << distance[e] << '\n';
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> *adj;
    adj = new vector<pair<int, int>>[n];
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        int c;
        string st;
        getline(cin, st);
        istringstream iss(st);
        while ( iss >> c) {
            int t = i-1;
            addAdj(adj, t, c-1, 1);
        }
    }
    int s, e;
    cin >> s >> e;
    dijkstra(adj, n, s - 1, e - 1);
    return 0;
}
//5
//2 4
//1
//1 5
//2 3
//5
//2 3



// 3
// 2
// 1
// 1
// 2 3