#include <iostream>
/*
---------------IMPORTANT-----------------
This program is 100% working in online compiler
*/
#include <string>
#include <algorithm>
using namespace std;
#define endl "\n"
#define MAX 99999


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
        int p[MAX], d[MAX], newsPriMap[MAX] = { 0 };
        string* news = new string[n];
        int pri, dis;
        int didx = 0, pidx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> news[i] >> pri >> dis;
            if (dis == 0)
                d[didx++] = pri;
            else
                p[pidx++] = pri;
            newsPriMap[pri] = i;
        }
        if (pidx > 0)
            sort(p, p + pidx);
        if (didx > 0)
            sort(d, d + didx);
        if (pidx > 0) {
            for (int i = pidx - 1; i >= 0; i--)
                cout << news[newsPriMap[p[i]]] << endl;
        }
        if (didx > 0) {
            for (int i = didx - 1; i >= 0; i--)
                cout << news[newsPriMap[d[i]]] << endl;
        }

    }
    return 0;
}
