#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getNextGreaterLinear(vector<int> nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n);

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums[i])
                st.pop();
            if (!st.empty())
                res[i] = st.top();
            else
                res[i] = -1;
            st.push(nums[i]);
        }
    }

    int maxAreaHistogram(vector<int> nums)
    {
        stack<int> st;
        int n = nums.size();
        int maxA = 0;
        for(int i = 0;i<=n;i++) {
            while (!st.empty() && (i == n || nums[st.top()] > nums[i]))
            {
                int height = nums[st.top()];
                st.pop();
                int width;
                if(st.empty()) // all are large // that means from nums[0...i] is area
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA,width*height);
            }
            st.push(i);
        }
        return maxA;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solution s;
    cout << s.findTheWinner(5, 2);
}