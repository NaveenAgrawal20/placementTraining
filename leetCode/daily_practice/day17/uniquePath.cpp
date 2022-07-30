#include<bits/stdc++.h>
#include<chrono>
using namespace std;

class Solution {
    int rows, cols;
    int count = 0;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rows = obstacleGrid.size();
        cols = obstacleGrid[0].size();
        // is 0,0 is obstacle none possible
        if (obstacleGrid[0][0] == 1)
            return 0;

        // path possible to reach from 0,0 to 0,0 = 1
        obstacleGrid[0][0] = 1;
        // filling first row
        /*
        0,j = 1 only if possible to access from previous path(left) and i,j is not an obstacle
        as only (right side allow) so
        */
        for (int i = 1; i < cols; ++i)
            obstacleGrid[0][i] = (obstacleGrid[0][i - 1] == 1 && obstacleGrid[0][i] == 0)
                                 ? 1 : 0;

        // filling first column
        // as only (down side allow) so
        for (int i = 1; i < rows; ++i)
            obstacleGrid[i][0] = (obstacleGrid[i - 1][0] == 1 && obstacleGrid[i][0] == 0) ? 1 : 0;

        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                // if not an obstacle
                if (obstacleGrid[i][j] == 0)
                    obstacleGrid[i][j] = obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j]; //left + top

                else
                    obstacleGrid[i][j] = 0;
            }
        }
        return obstacleGrid[rows - 1][cols - 1];
    }
};
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
int main()
{
    init_code();
    int t = 5;
    while (t--)
    {
        string s;
        cin >> s;
        vector<vector<int>> grid;

        int i = 0;
        while (true)
        {
            vector<int> v;
            for (; i < s.size(); ++i) {
                if (s[i] == ']')
                {
                    i++;
                    break;
                }
                else if (ispunct(s[i]) == 0)
                {
                    string str;
                    while (ispunct(s[i]) == 0)
                        str += s[i++];
                    i--;
                    v.push_back(stoi(str));
                }
            }
            if (i == s.size())
                break;
            grid.push_back(v);
        }
        // cout<<"Str = "<<s<<'\n';
        // for(auto e:grid)
        // {
        //     for(auto v:e)
        //         cout<<v<<' ';
        //     cout<<'\n';
        // }

        auto start = chrono::high_resolution_clock::now();

        /* MAIN FUNCTION */
        Solution obj;
        cout << obj.uniquePathsWithObstacles(grid) << endl;


        auto end = chrono::high_resolution_clock::now();

        // Calculating total time taken by the program.
        double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;

        cout << "Time taken by program is : " << fixed
             << time_taken << setprecision(9);
        cout << " sec" << endl;
    }

}