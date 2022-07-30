#include <iostream>
#include <string>
#include <vector>
#define endl "\n";
using namespace std;

void solve(int a[], int pos, int k, int siz, vector<int>& str)
{
    if (k <= 0)
    {
        int s = str.size();
        for (int j = 0; j < s; j++)
            cout << str[j] << " ";
        cout << endl;
        return;
    }
    for (int i = pos; i < siz; i++)
    {
        str.push_back(a[i]);
        solve(a, i + 1, k - 1, siz, str);
        str.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, k;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    vector<int> str;
    solve(a, 0, k, n, str);

    return 0;
}
/*
3
1 2 3
2
5
6 1 4 2 3
3

10
10 9 8 7 6 5 4 3 2 1
1
*/