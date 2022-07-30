#include<iostream>
using namespace std;

bool adjMatrix[6][6];

void addEdge(int u, int  v){
    adjMatrix[u][v] = adjMatrix[v][u] = true;
}
void printMat(){
    for(int i = 0;i<6;i++){
        for(int j = 0;j<6;j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    for (int i = 0; i < 6; ++i) {
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    printMat();
    return 0;
}