#include<bits/stdc++.h>
using namespace std;
vector<int> sortArrayByParity(vector<int>& nums) {
    int i = 0, j = nums.size() - 1;

    while(j >= i)
    {
        if(nums[i] & 1) //odd
        {
            if((nums[j] & 1) == 0) //even
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            else
                j--;
        }
        else
            i++;
    }
    return nums;
}

int main()
{
    vector<int> nums = {3,1,2,4};
    sortArrayByParity(nums);
}