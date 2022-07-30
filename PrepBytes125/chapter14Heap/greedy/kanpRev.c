#include<stdio.h>
#include<stdlib.h>

struct Item
{
    float profit,wt,pw;
};
typedef struct Item Item;

int comp(const void *a,const void *b){
    Item *i1 = (Item*)a;
    Item *i2 = (Item*)b;
    if(i1->pw > i2->pw)
        return 1;
    if(i1->pw < i2->pw)
        return -1;
    return 0;
}

void knap(Item *items,int n,float cap){
    qsort(items,n,sizeof(Item),comp);
    int i = 0, flag = 0;
    float totalProfit = 0,totalW = 0;
    for(i = n-1;i>=0;i--){
        int currWt = items[i].wt;
        if(cap - currWt > 0){
            totalProfit += items[i].profit;
            cap -= currWt;
        }else{
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        totalProfit += items[i].profit * (cap/items[i].wt);
    }
    printf("\nTotal Profit is = %f\n",totalProfit);
}


int main(){
    int n,i;
    float cap;
    scanf("%d",&n);
    Item *items = (Item *)malloc(sizeof(Item)*n);
    scanf("%f",&cap);
    for(i = 0;i<n;i++)
        scanf("%f",&items[i].wt);
    for(i = 0;i<n;i++)
        scanf("%f",&items[i].profit);
    for(i = 0;i<n;i++)
        items[i].pw = items[i].profit/items[i].wt;
    knap(items,n,cap);
}