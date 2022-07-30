#include<iostream>
#include<vector>
#include<list>

using namespace std;

/***
 * Directed Acyclic Graph (no cycle)
 * */
void printList(vector<int> vec[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Adjacency nodes of node " << i << " is :\n";
        for (int ele:vec[i]) {
            cout << "--> " << ele << "\n";
        }
    }
}

void addEdge(vector<int> *adj, int u, int v) {
    adj[u].push_back(v);
}

void topoLogicalSort(vector<int> *adj, int n) {
    // Count InDegree
    int *inDegree = new int[n]{0};
    int topoLogicalList[n];

    for (int i = 0; i < n; ++i) {
        for (int ele:adj[i]) {
            inDegree[ele]++;
        }
    }

    // fill queue with 0 inDegree node
    list<int> q;

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0)
            q.push_back(i);
    }

    int curr, j = 0;
    while (!q.empty()) {
        curr = q.front();
        q.pop_front();
        topoLogicalList[j++] = curr;
        for (int ele:adj[curr]) {
            inDegree[ele]--;
            if (inDegree[ele] == 0)
                q.push_back(ele);
        }
    }
    for(int i = 0;i<n;++i){
        cout<<topoLogicalList[i]<<" ";
    }
    cout<<'\n';
}

int main() {
    int n, numVert;
    vector<int> *adj;
    cin >> n >> numVert;
    adj = new vector<int>[numVert];

    for (int i = 1; i <= n; i++) {
        int from, to;
        cin >> from >> to;
        addEdge(adj, from, to);
    }
    topoLogicalSort(adj, numVert);
//    printList(adj, numVert);
    return 0;
}


/*
9 12
7 11
5 11
7 8
3 8
11 2
11 9
8 9
11 10
3 10

6 6
5 2
5 0
4 0
4 1
2 3
3 1

9 8
0 6 1 2 1 4 1 6 3 0 3 4 5 1 7 0 7 1
 */
