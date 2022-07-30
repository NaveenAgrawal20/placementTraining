#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int solve(ll g[], ll c[], int n) {
    int i, j;
    int cost, gidx;
    for (i = 0; i < n; i++) {
        if (g[i] >= c[i]) {
            gidx = i;
            cost = g[i] - c[i];

            int currCost = 0;
            j = (gidx + 1) % n;
            do {
                currCost = g[j] + cost - c[j];
                if (currCost >= 0)
                    cost = currCost;
                else
                    break;
                j = (j + 1) % n;
            } while (j != gidx);
            if(j == gidx)
                return j;
        }
    }
    return -1;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    int T = 7;
    while (T--) {
        int n;
        cin >> n;
        ll g[n], c[n];
        for (int i = 0; i < n; i++)
            cin >> g[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];

        ///////////////////
        cout << solve(g, c, n) << "\n";
    }
    return 0;
}
/*
4
4 6 7 4
6 5 3 5
5
1 2 3 4 5
3 4 5 1 2
5
1 2 3 4 5
3 4 5 1 5
5
1 2 3 4 5
3 4 5 5 5
3
2 3 4
3 4 3
5
1 2 3 4 5
3 4 7 1 2
5
5 1 2 3 4
4 4 1 5 1
*/