#include <iostream>
#include <vector>
#include <queue>
#define N 1000
using namespace std;
class cell
{
public:
    int x, y, dis;
    cell() {}
    cell(int x, int y, int dis)
        : x(x), y(y), dis(dis)
    {
    }
};

bool isValid(int x,int y){
    if (x >= 1 && x <= N && y >= 1 && y <= N)
		return true;
	return false;
}

int miniPath(int kPos[2])
{
    bool visited[N + 1][N + 1];
    vector<pair<int, int>> dir = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    queue<cell> q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            visited[i][j] = false;
        }
    }
    cell temp;
    int newX,newY;
    // pushing starting position of knight with 0 distance
    q.push(cell(kPos[0], kPos[1], 0));
    visited[kPos[0]][kPos[1]] = true;
    while (!q.empty())
    {
        temp = q.front();q.pop();
        if(temp.x == 1 && temp.y == 1)
            return temp.dis;
        for(int i = 0;i<8;i++){
            newX = temp.x + dir[i].first;
            newY = temp.y + dir[i].second;
            if(isValid(newX,newY) && !visited[newX][newY]){
                q.push(cell(newX,newY,temp.dis+1));
            }
        }
    }
    return temp.dis;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int kPos[2] = {x, y};
        cout << miniPath(kPos) << "\n";
    }
    return 0;
}
/*
3
4 9
7 7
5 4
*/