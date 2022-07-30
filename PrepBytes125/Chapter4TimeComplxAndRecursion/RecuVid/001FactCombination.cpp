#include <iostream>
#include <string>
#define endl "\n";
using namespace std;

void solve(int n, int p, string str)
{
    if (n == 1)
    {
        cout << str << endl;
        return;
    }
    for (int i = p; i <= n; i++)
    {
        if (n % i == 0)
        {
            str += to_string(i) + " ";
            solve(n / i, i, str);
            str.pop_back();     // for space
            str.pop_back();     // for number
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // string g = "1 ";
    // int t = 2;
    // g += to_string(t)+" --";
    // cout<<g;
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string str = "1 ";
        int p = 2;
        solve(n, p, str);
    }
    return 0;
}