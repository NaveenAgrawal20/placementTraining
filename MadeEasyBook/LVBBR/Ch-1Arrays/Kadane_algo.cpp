// Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers that has the largest sum. 
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int *a,int n)
{
    int max_sum = INT_MIN;
    int current_max = 0;
    for(int i = 0;i<n;++i)
    {
        current_max = current_max + a[i];
        if(current_max < 0)
        {
            current_max = 0;
        }
        if( max_sum < current_max)
            max_sum = current_max;
        
    }
    return max_sum;
}
int maxAbsoluteSum(int *a,int n) {
    int cmin = 0,cmax = 0;
    int min = INT_MAX,max = INT_MIN;
    for(int i = 0;i<n;++i)
    {
        cmax += a[i];
        if(cmin > 0)
            cmin = a[i];
        else
            cmin += a[i];
        if(min > cmin)
            min = cmin;
        if(cmax < 0)
            cmax = 0;
        if(max < cmax)
            max = cmax;
    }
    cout<<min<<" and "<<max<<'\n';
    return max > abs(min)?max:abs(min);
}

int main()
{
    int a1[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int a2[] = {-2, -3, 4};
    int a3[] = {-2, -3};
    int a4[] = {1,-2, -3, 4};
    int a5[] = {1,4, -6, 4};
    int a6[] = {1,4, -6, 6}, a7[] = {1,-3,2,3,-4}, a8[] = {2,-5,1,-4,3,-2};
    int n = sizeof(a1)/sizeof(a1[0]);

    int a9[] = {-7,-1,0,-2,1,3,8,-2,-6,-1,-10,-6,-6,8,-4,-9,-4,1,4,-9};
    int a10[] = {-6,7,7,3,1,7,6,9,1,9,-5,1,6,6,-3,0,-3,5,-8,1};
    
    cout << "Maximum contiguous sum is 7 = " << maxAbsoluteSum(a1, n)<<'\n';
    cout << "Maximum contiguous sum is 5 = " << maxAbsoluteSum(a2, 3)<<'\n';
    cout << "Maximum contiguous sum is 5 = " << maxAbsoluteSum(a3, 2)<<'\n';
    cout << "Maximum contiguous sum is 5 = " << maxAbsoluteSum(a4, 4)<<'\n';
    cout << "Maximum contiguous sum is 6 = " << maxAbsoluteSum(a5, 4)<<'\n';
    cout << "Maximum contiguous sum is 6 = " << maxAbsoluteSum(a6, 4)<<'\n';
    cout << "Maximum contiguous sum is 5 = " << maxAbsoluteSum(a7, 5)<<'\n';
    cout << "Maximum contiguous sum is 8 = " << maxAbsoluteSum(a8, 6)<<'\n';
    cout << "Maximum contiguous sum is 44 = " << maxAbsoluteSum(a9,  sizeof(a9)/sizeof(a9[0]))<<'\n';
    cout << "Maximum contiguous sum is 58 = " << maxAbsoluteSum(a10,  sizeof(a10)/sizeof(a10[0]))<<'\n';
    // cout << "Maximum contiguous sum is " << maxSubArraySum(a1, n)<<'\n';
    // cout << "Maximum contiguous sum is " << maxSubArraySum(a2, 3)<<'\n';
    // cout << "Maximum contiguous sum is " << maxSubArraySum(a3, 2)<<'\n';
    // cout << "Maximum contiguous sum is " << maxSubArraySum(a4, 4)<<'\n';
    // cout << "Maximum contiguous sum is " << maxSubArraySum(a5, 4)<<'\n';
    // cout << "Maximum contiguous sum is " << maxSubArraySum(a6, 4)<<'\n';
    return 0;
}

