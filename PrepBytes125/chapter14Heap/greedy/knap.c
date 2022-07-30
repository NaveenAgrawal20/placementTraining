#include <stdio.h>
#include <stdlib.h>
struct Item
{
    float profit, weight, pw;
};
typedef struct Item Item;
int comp(const void *a,const void *b){
    Item *i1 = (Item*)a;
    Item *i2 = (Item*)b;
    float t1 = i1->pw;
    float t2 = i2->pw;
    if(t1 < t2)
        return -1;
    else if(t1 > t2)
        return 1;
    return 0;
}

void fractionalKnapsack(Item items[],int cap,int n){

    qsort(items,n,sizeof(Item),comp);
    int flag = 0;
    float totalProfit = 0.0;
    // for(int k = 0;k<n;k++)
    //     printf("%f\t",items[k].pw);

    int i = 0;
    // Running Reverse (start from max pw)
    for(i = n-1;i>=0;--i){
        float currWt = items[i].weight;
        float currProfit = items[i].profit;
        if(cap - currWt > 0){
            cap = cap - currWt;
            totalProfit += currProfit;
        }else{
            flag = 1;
            break;
        }
    }
    if(flag){
        // cout<<items[i].profit * (cap/items[i].weight)<<endl;
        totalProfit += items[i].profit * (cap/items[i].weight);
    }
    printf("%f\n",totalProfit);
}

int main()
{
    int n;
    scanf("%d",&n);
    float cap;
    scanf("%f",&cap);

    float wt[n], profit[n];
    Item items[n];
    for (int i = 0; i < n; i++)
        scanf("%f",&wt[i]);

    for (int i = 0; i < n; i++)
        scanf("%f",&profit[i]);

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

3
50
20 30 10
100 120 60

7
15
2 3 5 7 1 4 1
10 5 15 7 6 18 3
*/