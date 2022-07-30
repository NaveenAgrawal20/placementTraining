#include <iostream>
#include <vector>
#define endl "\n";
using namespace std;

void solve(int n, int p, vector<int> &v)
{
    if (n == 1)
    {
        int s = v.size();
        for (int j = 0; j < s; j++)
            cout << v[j] << " ";
        cout << endl;
        return;
    }
    for (int i = p; i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            solve(n / i, i, v);
            v.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v;
        v.push_back(1);
        int p = 2;
        solve(n, p, v);
    }
    return 0;
}
/*
1
8
*/
/*
https://www.geeksforgeeks.org/sum-of-subsets-of-all-the-subsets-of-an-array-o2n/
*/