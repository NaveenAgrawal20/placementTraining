#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int minJumps(vector<int> arr)
{
    int n = arr.size();

    vector<int> jumps(n, 0);
    // last to last 0
    jumps[n - 1] = 0;
    int minJ;
    for (int i = n - 2; i >= 0; --i)
    {
        // cant jump for arr[i] = 0
        if (arr[i] == 0)
            jumps[i] = INT_MAX;
        // If we can directly reach to the end point from
        // here then jumps[i] is 1
        else if (arr[i] >= n - i - 1)
            jumps[i] = 1;
        else
        {
            minJ = INT_MAX;
            for (int j = i + 1; j < n && j <= arr[i] + i; ++j)
            {
                minJ = min(minJ, jumps[j]);
            }
            if (minJ != INT_MAX)
                jumps[i] = minJ + 1;
            else
                jumps[i] = i;
        }
    }
    return jumps[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // vector<int> arr = {1, 3, 6, 1, 0, 9};
    vector<int> arr = {1, 1, 1, 1};
    cout << minJumps(arr) << '\n';
    return 0;
}