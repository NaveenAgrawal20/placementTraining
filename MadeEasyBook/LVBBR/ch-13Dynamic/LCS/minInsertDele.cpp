#include <iostream>
using namespace std;

void solve(string a, string b)
{
    int aLen = a.length();
    int bLen = b.length();

    int dp[aLen + 1][bLen + 1];
    for (int i = 0; i <= aLen; ++i)
    {
        for (int j = 0; j <= bLen; ++j)
        {
            if (i == 0 || j == 0) // row = 0 or col = 0
            {
                dp[i][j] = 0;
                continue;
            }
            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int lcsLen = dp[aLen][bLen];
    cout << "\nDeletion required = " << aLen - lcsLen;
    cout << "\nInsertion required = " << bLen - lcsLen << '\n';
}

int main()
{
    string a, b;
    cin >> a >> b;
    solve(a, b);
    return 0;
}