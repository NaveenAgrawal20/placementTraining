#include <iostream>
using namespace std;

int main()
{

    int n, i, max = -999;
    cin >> n;
    int a[n + 1];
    for (i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
    }
    bool isNoAp[max + 1];
    int prev[max + 1] = {0}, diff[max + 1] = {0};

    int curr, count = 0;
    for (i = 1; i < n + 1; i++)
    {
        int curr = a[i];
        if (!isNoAp[curr])
        {
            if (prev[curr] > 0)
            {
                if (diff[curr] == 0) // update only one time
                    diff[curr] = i - prev[curr];
                else if (diff[curr] != i - prev[curr])
                {
                    isNoAp[curr] = true;
                    --count;
                }
            }
            else
            {
                count++;
            }
            prev[curr] = i;
        }
    }

    cout << count << "\n";
    for (i = 1; i < max + 1; i++)
    {
        // if element is present it will have index from 1 to max
        if (!isNoAp[i] && prev[i])
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