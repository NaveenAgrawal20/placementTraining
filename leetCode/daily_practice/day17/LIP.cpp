class Solution {
	int rows,cols;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	int ans = 1;
        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<int>> dp(rows,vector<int> (cols)); 
        // dp = vector<vector<int>>(rows);

	    for(int i = 0;i<rows;++i)
	    {
	    	for(int c = 0;c<cols;++c)
            {
                dfs(i,c,-1,matrix,dp);
	        	ans = max(ans, dp[i][c]);
            }
	    }
	    return ans;
    }

    // prevVal for previous value comparison
    int dfs(int r, int c, int prevVal,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
    	if(r < 0 || r >= rows ||
    		 c < 0 || c >= cols ||
    		prevVal >= matrix[r][c])
    		return 0;
    	if (dp[r][c] != 0) // computed
    		return dp[r][c];
    	
    	int res = 1;
    	// moving in 4 directions. // clockwise
    	res = max(res,1+dfs(r-1,c,matrix[r][c],matrix,dp));
    	res = max(res,1+dfs(r,c+1,matrix[r][c],matrix,dp));
    	res = max(res,1+dfs(r+1,c,matrix[r][c],matrix,dp));
    	res = max(res,1+dfs(r,c-1,matrix[r][c],matrix,dp));
    	dp[r][c] = res;
    	return res;
    }
};
/*

For DP we could have used
==>
std::map<std::pair<int,int>, int> myMap;
myMap[std::make_pair(10,20)] = 25;
std::cout << myMap[std::make_pair(10,20)] << std::endl;
*/