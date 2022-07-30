#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<pair<string, double>>> adjList;
unordered_map<string, bool> visited;
double queryAns;

double DFS(string startNode, string endNode)
{
    // no ans can be found
    if (adjList.find(startNode) == adjList.end())
    {
        return -1;
    }
    // if query=(x,x) (x/x = true(always)) and x must be present (see Example case 1)
    if (startNode == endNode && adjList.find(startNode) != adjList.end())
    {
        return 1;
    }

    double productAns;
    visited[startNode] = true;

    int n = adjList[startNode].size();
    for (int i = 0; i < n; ++i)
    {
        pair<string, double> vertex = adjList[startNode][i];
        if (!visited[vertex.first])
        {
            productAns = DFS(vertex.first, endNode);
            if (productAns != -1)
                return productAns * vertex.second;
        }
    }
    return -1;
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    int n = equations.size(), m = queries.size();
    vector<double> ansList(m);

    for (int i = 0; i < n; ++i)
    {
        adjList[equations[i][0]].push_back({equations[i][1], values[i]});
        adjList[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        visited[equations[i][0]] = visited[equations[i][1]] = false;
    }

    for (int i = 0; i < m; ++i)
    {
        DFS(queries[i][0], queries[i][1]);
    }
    return ansList;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double> ans = calcEquation(equations, values, queries);
    for(auto& e:ans)
        cout<<e<<' ';
    return 0;
}