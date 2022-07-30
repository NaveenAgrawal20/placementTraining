from typing import List
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        maxSum = sum(nums)
        n,reqSum = len(nums),target+maxSum

        if(reqSum & 1 != 0 or reqSum < target): # odd
            return 0
        reqSum = reqSum//2
        dp = [[0]*(reqSum+1) for _ in range(n+1)]
        for i in range(n+1):
            dp[i][0] = 1
        # for i in range(0,n+1):
        #     for j in range(0,reqSum+1):
        #         print(dp[i][j],end='\t')
        #     print()

        for i in range(1,n+1):
            for j in range(0,reqSum+1):
                dp[i][j] = dp[i-1][j]
                if(nums[i-1] <= j):
                    dp[i][j] = dp[i][j] + dp[i-1][j-nums[i-1]]

        return dp[n][reqSum]



n = int(input())
nums = [int(x) for x in input().split()]
target = int(input())
print(nums)
s = Solution()
print(s.findTargetSumWays(nums,target))
"""
4
1 2 3 4
2

3
0 0 0 0 0 0 0 0 1
1
"""