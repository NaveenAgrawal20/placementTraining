#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

void solve(int *p, int n, int v1, int v2) {
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][i] = min(p[i - 1] * v1, p[i - 1] * v2);

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l+1; i++) {
            int j = l - 1 + i;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost1 = (dp[i][k] + dp[k + 1][j]) * v1;
                int cost2 = (dp[i][k] + dp[k + 1][j]) * v2;
                dp[i][j] = min(dp[i][j],min(cost1, cost2));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }

    cout << "Min mutli is  = " << dp[1][n] << ' ';
}

int main() {
    // int arr[] = {2,3,5,6,7};
    // int arr[] = {3, 100, 2, 2};
    int arr[] = {10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n, 2, 4);
    return 0;
}
/*
#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

void solve(int *p, int n, int v1, int v2) {
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[i][i] = min(p[i - 1] * v1, p[i - 1] * v2);

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l+1; i++) {
            int j = l - 1 + i;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int cost1 = (dp[i][k] + dp[k + 1][j]) * v1;
                int cost2 = (dp[i][k] + dp[k + 1][j]) * v2;
                dp[i][j] = min(dp[i][j],min(cost1, cost2));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }

    cout << "Min mutli is  = " << dp[1][n] << ' ';
}

int main() {
    // int arr[] = {2,3,5,6,7};
    // int arr[] = {3, 100, 2, 2};
    int arr[] = {10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    solve(arr, n, 2, 4);
    return 0;
}
*/
