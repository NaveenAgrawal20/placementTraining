#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define MAX 20

bool isSafe(int x, int y, int n, int graph[][MAX]) {
    if (x < 0 || y < 0 || x >= n || y >= n || (graph[x][y] == 0))
        return false;
    return true;
}

class DIR {
public:
    int x, y;
    char d;

    DIR(int a, int b, char c) : x{a}, y{b}, d{c} {}
};

vector<DIR> dir = {
        DIR(-1, 0, 'U'),
        DIR(0, 1, 'R'),
        DIR(1, 0, 'D'),
        DIR(0, -1, 'L')
}; // ULDR
void sol(int graph[][MAX], int row, int col, int n, vector<string> &possiblePath, string path, bool visited[][MAX]) {
    visited[row][col] = true;
    if (row == n - 1 && col == n - 1) {
        possiblePath.push_back(path);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int newRow = row + dir[i].x;
        int newCol = col + dir[i].y;
        char dr = dir[i].d;
        if (isSafe(newRow, newCol, n, graph) && !visited[newRow][newCol]) {
            path.push_back(dr);
            sol(graph, newRow, newCol, n, possiblePath, path, visited);
            visited[newRow][newCol] = false;
            path.pop_back();
        }

    }
}

int main() {
//    int n;
//    cin >> n;
//    int graph[][MAX] = { { 1, 0, 0, 0, 0 },
//                                 { 1, 1, 1, 1, 1 },
//                                 { 1, 1, 1, 0, 1 },
//                                 { 0, 0, 0, 0, 1 },
//                                 { 0, 0, 0, 0, 1 } };
    int graph[][MAX] = {{1, 0, 1},
                        {1, 1, 1},
                        {1, 1, 1}
    };
    int n = sizeof(graph) / sizeof(graph[0]);

    vector<string> possiblePath;
    string path;
    bool visited[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    }
    sol(graph, 0, 0, n, possiblePath, path, visited);
    for (const string &p:possiblePath) {
        cout << p << "\t";
    }
    cout << endl;
    return 0;
}