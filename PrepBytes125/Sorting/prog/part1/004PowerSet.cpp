#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define endl "\n"

void solve(string s, int p, int n, string str)
{
    if (p >= n)
        return;
    for (int i = p; i < n; i++)
    {
        str += s[i];
        cout << str << endl;
        solve(s, i + 1, n, str);
        str.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    solve(s, 0, s.size(), "");
    return 0;
}
/*
1
abc
*/