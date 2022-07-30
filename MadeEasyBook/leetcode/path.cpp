#include<bits/stdc++.h>
using namespace std;

class Solution {
    int rows, cols;
    int count = 0;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rows = obstacleGrid.size();
        cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));

        dp[0][0] = 1;
        for(int i = 0;i<rows;i++)
        {
            for(int j = 0;j<cols;++j)
            {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                    if(i == 0)
                        dp[i][j] = j > 0 ?dp[i][j-1]:dp[i][j];
                    else if(j == 0)
                        dp[i][j] = i > 0 ?dp[i-1][j]:dp[i][j];
                    else
                        dp[i][j]  = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        int m = rows-1;
        int n = cols-1;
        return dp[m][n];
    }

    int longestIncreasingSubs()
    {
        vector<int> nums = {10,9,2,5,3,5,7,101,18};
        vector<int> res;
        for(auto i:nums){
            auto it=lower_bound(res.begin(), res.end(), i);
            if(it==res.end())
                res.push_back(i);
            else
            {
                cout<<"\nIn else for = "<<i<<" and "<<*it<<'\n';
                *it=i;
                cout<<*it<<endl;
            }
        }
        return res.size();
    }
};
int main()
{
    Solution s;
    cout<<s.solve();
//    int t = 5;
//    while(t--)
//    {
//        string s;
//        cin>>s;
//        vector<vector<int>> grid;
//
//        int i = 0;
//        while(true)
//        {
//            vector<int> v;
//            for(;i<s.size();++i) {
//                if (s[i] == ']')
//                {    i++;
//                    break;
//                }
//                else if(ispunct(s[i]) == 0)
//                    v.push_back(s[i]-'0');
//            }
//            if(i == s.size())
//                break;
//            grid.push_back(v);
//        }
//        // cout<<"Str = "<<s<<'\n';
//        // for(auto e:grid)
//        // {
//        //     for(auto v:e)
//        //         cout<<v<<' ';
//        //     cout<<'\n';
//        // }
//        Solution obj;
//        cout<<obj.uniquePathsWithObstacles(grid)<<endl;
//    }

}