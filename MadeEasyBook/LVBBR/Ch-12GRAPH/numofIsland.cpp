#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    
    if (grid[i][j] == '1')
    {
        grid[i][j] = '0';
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i, j - 1, n, m);
        dfs(grid, i, j + 1, n, m);
    }
    
}

int numIsland(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == '1')
            {
                grid[i][j] = '0';
                dfs(grid, i - 1, j, n, m);
                dfs(grid, i + 1, j, n, m);
                dfs(grid, i, j - 1, n, m);
                dfs(grid, i, j + 1, n, m);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n = 4, m = 5;
    vector<vector<char>> grid(n);
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < m; ++j)
        {
            char t;
            cin >> t;
            grid[i].push_back(t);
        }
    }
    // for (int i = 0; i < grid.size(); i++)
    // {
    //     for (int j = 0; j < m; ++j)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
        cout <<numIsland(grid)<<endl;
    // }
    // grid = [
    //     [ "1", "1", "0", "0", "0" ],
    //     [ "1", "1", "0", "0", "0" ],
    //     [ "0", "0", "1", "0", "0" ],
    //     [ "0", "0", "0", "1", "1" ]
    // ];
    return 0;
}
/*
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
*/
