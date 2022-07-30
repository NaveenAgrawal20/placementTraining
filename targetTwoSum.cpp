#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve(vector<int> nums, int t)
{
    unordered_map<int, int> setTab;
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        unordered_map<int, int>::iterator it = setTab.find(t - nums[i]);
        if (it != setTab.end())
            cout << it->second << ' ' << i;
        else
            setTab.insert(make_pair(nums[i], i));
    }
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    solve(nums, 9);
    return 0;
}