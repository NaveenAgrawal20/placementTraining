#include <iostream>
#include <algorithm>
using namespace std;

class Item
{
    public:
    float profit, weight, pw;
};
bool comp(Item a,Item b){return a.pw < b.pw;}

void fractionalKnapsack(Item items[],int cap,int n){
    sort(items,items+n,comp);
    bool flag = false;
    float totalProfit = 0.0;
    int i = 0;
    // Running Reverse (start from max pw)
    for(i = n-1;i>=0;--i){
        float currWt = items[i].weight;
        float currProfit = items[i].profit;
        if(cap - currWt > 0){
            cap = cap - currWt;
            totalProfit += currProfit;
        }else{
            flag = true;
            break;
        }
    }
    if(flag){
        cout<<items[i].profit * (cap/items[i].weight)<<endl;
        totalProfit += items[i].profit * (cap/items[i].weight);
    }
    cout<<totalProfit<<'\n';
}

int main()
{
    int n;
    cin>>n;
    float cap;
    cin >> cap;
    float wt[n], profit[n];
    Item items[n];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    for (int i = 0; i < n; i++)
    {
        items[i].weight = wt[i];
        items[i].profit = profit[i];
        items[i].pw = profit[i]/wt[i];
    }
    fractionalKnapsack(items,cap,n);
    return 0;
}

/*
5
60
5 10 15 22 25
30 40 45 77 90
*/