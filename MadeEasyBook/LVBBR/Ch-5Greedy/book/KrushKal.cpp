#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
    int src,dest,wt;
    Edge(){}
    Edge(int u,int v,int w):src(u),dest(v),wt(w){};
};

bool comp(Edge &a,Edge &b)
{
    return a.wt < b.wt;
}

int getSet(int v,int *vertexSet) // find operation of set
{
    if(v == vertexSet[v])
        return v;
    else
        return getSet(vertexSet[v],vertexSet);
}

vector<Edge> krushkalsalgo(vector<Edge>& graph,int n)
{
    int *vertexSet = new int[n];
    for(int i = 0;i<n;++i)
        vertexSet[i] = i;
    sort(graph.begin(),graph.end(),comp);

    int count = 0,i = 0;
    vector<Edge> res;
    while(count < n-1)
    {
        Edge current = graph[i];
        int uSet = getSet(current.src,vertexSet);
        int vSet = getSet(current.dest,vertexSet);
        
        if(uSet != vSet)
        {
            res.push_back(current);
            count += 1;
            vertexSet[vSet] = uSet; 
        }
        i += 1;
    }
    return res;
}


int main()
{
    int n,e;
    cin>>n>>e;
    vector<Edge> graph(e);
    for (int i = 0; i < e; i++)
        cin>>graph[i].src>>graph[i].dest>>graph[i].wt;
    
    vector<Edge> res = krushkalsalgo(graph,n);
    for(Edge ed:res)
        cout<<ed.src<<"->"<<ed.dest<<" = "<<ed.wt<<'\n';
    return 0;
}
/*
7 9
0 5 10
5 4 15
4 3 12
3 2 2
2 1 6
1 0 18
1 6 4
6 3 8
6 4 14
*/