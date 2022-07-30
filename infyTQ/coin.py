def coinChange( coins, amt: int) -> int:
        dp = [float('Inf')]*(amt+1)
        dp[0] = 0
        n = len(coins)
        for i in range(1,amt+1):
            for j in range(0,n):
                if coins[j] <= i:
                    dp[i] = min(dp[i],1+dp[i-coins[j]])
        for i in range(0,amt+1):
            print(dp[i],end=' ')
        return dp[amt] if dp[amt] != float('inf') else -1

coins = [1,5,10,20,25,50]
print(coinChange(coins,40))
print(coinChange(coins,5))
print(coinChange(coins,10))
print(coinChange(coins,20))
print(coinChange(coins,55))