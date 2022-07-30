#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mobileTower(vector<int> x,int range)
{
    int n = x.size();
    sort(x.begin(),x.end());
    
    int numOfTower = 0;
    int i = 0;
    while(i<n)
    {
        numOfTower++;
        int loc = x[i]+range;
        while(x[i] <= loc && i<n)
            i++;
        i--;
        loc = x[i] + range;
        while(x[i] <=loc && i<n)
            i++;
    }
    return numOfTower;
}

int main()
{
    vector<int> houses = { 7, 2, 4, 6, 5, 9, 12, 11 };
    cout<<"Tower = "<<mobileTower(houses,2)<<'\n';
    return 0;
}