#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
int maxOperations(vector<int>& nums, int k) {
    int n = nums.size(), count = 0;
    unordered_map<int,int> hashSet;
    for(int i = 0;i<n;++i)
    {
        int complement = k - nums[i];
        if(hashSet.find(complement) != hashSet.end())
        {
            if(hashSet[complement] == 1)
                hashSet.erase(complement);
            else
                hashSet[complement] -= 1;
            count++;
        }
        else
        {
            if(hashSet.find(nums[i]) != hashSet.end())
            {
                hashSet[nums[i]] += 1;
            }
            else
            {
                hashSet.insert({nums[i],1});
            }
        }
    }
    return count;
}
int main()
{
    vector<int> v = {2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2};
    cout<<maxOperations(v,3);
}