#include<iostream>
#include<algorithm>
using namespace std;

class Job{
    public:
    int id,profit,deadline;
    Job(){};
    Job(int id,int dl,int profit):id(id),deadline(dl),profit(profit){};
};

bool cmp(Job a,Job b)
{
    return a.profit > b.profit;
}

void jobSequencing(Job jobs[],int n)
{
    sort(jobs,jobs+n,cmp); // decreasing order of jobs by profit
    
    bool slots[n] = {false};
    // for(int i = 0;i<n;i++)
    // {
    //     cout<<jobs[i].id<<" "<<jobs[i].deadline<<" "<<jobs[i].profit<<'\n';
    // }

    int result[n];
    for(int i = 0;i<n;++i)
    {
        for(int j = min(jobs[i].deadline-1,n-1);j>=0;j--)
        {
            if(!slots[j]) // slot not filled
            {
                slots[j] = true;
                result[j] = i;
                break;
            }
        }
    }
    int totalProfit = 0;
    for(int i = 0;i<n;i++)
    {
        if(slots[i])
        {
            cout<<jobs[result[i]].id<<' ';
            totalProfit += jobs[result[i]].profit;
        }
    }
    cout<<'\n'<<totalProfit<<'\n';
}

int main()
{
    int n; // num of jobs
    cin>>n;
    Job jobs[n];
    for (int i = 0; i < n; i++)
    {
        int id,dl,pr;
        cin>>id>>dl>>pr;
        jobs[i] = Job(id,dl,pr);
    }
    jobSequencing(jobs,n);
    return 0;
}

/*
9
1 7 15
2 2 20
3 5 30
4 3 18
6 5 10
7 2 23
8 7 16
9 3 25
5 4 18

7
1 3 35
2 4 30
3 4 25
4 2 20
5 3 15
6 1 12
7 2 5
ans
2 7 9 5 3 1 8
147
*/