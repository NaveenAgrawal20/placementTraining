#include <iostream>
using namespace std;

bool isNoAp[100001];
int prevIdx[100001],diff[100001];

int main()
{

    int n, i, max = -999;
    cin >> n;
    int a[n + 1];
    for (i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }

    int curr, count = 0;
    for (i = 1; i < n + 1; i++)
    {
        curr = a[i];
        if (!isNoAp[curr])
        {
            if (prevIdx[curr] > 0)
            {
                if (diff[curr] == 0) // update only one time
                    diff[curr] = i - prevIdx[curr];
                else if (diff[curr] != i - prevIdx[curr])
                {
                    isNoAp[curr] = true;
                    --count;
                }
            }
            else
            {
                count++;
            }
            prevIdx[curr] = i;
        }
    }
    cout << count << "\n";
    for (i = 1; i < 100001; i++)
    {
        if (!isNoAp[i] && prevIdx[i])
            cout << i << " " << diff[i] << "\n";
    }
}

/*
8
4 2 4 3 4 2 4 5

4
2 4
3 0
4 2
5 0
*/