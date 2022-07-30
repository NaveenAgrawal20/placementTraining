#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printMat(vector<vector<int>> mat){
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << " ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat;
        for (int i = 0; i < n; i++) {
            vector<int> v1;
            for (int j = 0; j < m; j++) {
                int e;
                cin >> e;
                v1.push_back(e);
            }
            mat.push_back(v1);
        }

        vector<vector<int>> ans(n, vector<int>(m, INT_MAX - 1));
        queue<pair<int, int>> q; // queue

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        int dir[4][2] = {{0,  -1},
                         {-1, 0},
                         {1,  0},
                         {0,  1}}; // directions
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // traverse in direction
            for (int i = 0; i < 4; i++) {
                int nextX = x + dir[i][0];
                int nextY = y + dir[i][1];
                if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < m) {
                    if (ans[nextX][nextY] > ans[x][y] + 1) {
                        ans[nextX][nextY] = ans[x][y] + 1;
                        q.push({nextX, nextY});
                    }
                }
            }
        }
        printMat(ans);
    }return 0;
}
/*
3 3
0 0 1
1 1 1
1 0 1*/