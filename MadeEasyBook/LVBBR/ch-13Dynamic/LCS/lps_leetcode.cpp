#include<bits/stdc++.h>

using namespace std;


string longestPalindrome(string a) {
    int n = a.size();
    bool dp[n][n];
    int len;
    int palinStart;
    // 0 gap (1 char)
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    for (int gap = 1; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; ++j, ++i) {
            if (gap == 1) // 2 characters (if extremes are equal than palindrome)
            {
                if (a[i] == a[j])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
            {
                if(a[i] == a[j] && dp[i+1][j-1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            if(dp[i][j])
            {
                palinStart = i;
                len = gap+1;
            }
        }
    }
    return a.substr(palinStart,len);
}

int main() {
    int t = 5;
    while (t--) {
        string str;
        cin >> str;
        cout << longestPalindrome(str) << '\n';
    }
    return 0;
}
/*
babad
cbbd
ccd
aacabdkacaa
abb
a
 * */