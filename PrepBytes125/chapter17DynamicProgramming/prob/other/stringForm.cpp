#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> dp;

bool solve(string t)
{
    if (dp[t] == 1)
        return true;
    string temp = "";
    for (int i = 0; i < t.length(); i++)
    {
        temp += t[i];
        if (dp[temp] == 1 && solve(t.substr(i + 1)))
        {
            dp[t] = 1;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        dp.clear();
        string target, temp;
        cin >> target;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            dp[temp] = 1;
        }
        cout << (solve(target)?"Yes":"No");
    }

    return 0;
}