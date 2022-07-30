#include<iostream>
using namespace std;


int profit(int *a,int n){
    int maxPrf = a[1] - a[0];
    int minEle = a[0];
    for(int i = 1;i<n;++i){
        maxPrf = max(maxPrf,a[i]-minEle);
        minEle = min(minEle,a[i]);
    }
    if(maxPrf < 0)
        return 0;
    return maxPrf;
}


int main()
{
    // int prices[] = {7, 1, 5, 3, 6, 4};
    int prices[] = {7, 6, 4, 3, 1};
    cout<<profit(prices,sizeof(prices)/sizeof(prices[0]));
    return 0;
}