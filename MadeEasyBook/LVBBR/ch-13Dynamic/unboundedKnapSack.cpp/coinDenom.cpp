#include <iostream>
using namespace std;
#define COIN_LEN 10
// int coins[COIN_LEN] = {1, 5, 10, 20, 25, 50};
int coins[COIN_LEN] = {1,2, 5, 10, 20, 50,100,200,500,2000};

int solveCoin_1D(int amt)
{
    // int dp[n+1][len+1];
    int dp[amt + 1];
    for (int i = 0; i <= amt; ++i)
        dp[i] = 9999;
    dp[0] = 0;
    for (int i = 1; i <= amt; i++)
    {
        for (int j = 0; j < COIN_LEN; j++)
        {
            if (coins[j] <= i)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }
    return dp[amt];
}

int main()
{
    int t = 15;
    while (t--)
    {
        int amt;
        cin >> amt;
        cout << solveCoin_1D(amt) << '\n';
    }
    return 0;
}
/*
8
1 2 3 4 5 6 7 8
1   5   8   9  10  17  17  20

8
1   2   3   4   5   6   7   8
3   5   8   9  10  17  17  20


dp = [float('Inf')]*(amount+1)
    dp[0] = 0
    coins.sort()
    for i in range(1,amount+1):
        temp = [float('Inf')]
        for c in coins:
            if i-c<0:
                break
            temp.append(dp[i-c])
        dp[i] = min(temp)+1

    return dp[amount] if dp[amount] != float('Inf') else -1

*/