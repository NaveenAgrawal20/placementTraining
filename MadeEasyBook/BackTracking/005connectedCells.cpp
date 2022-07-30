#include <iostream>
#include <string>
#define endl "\n"
#define MAX 5



using namespace std;
//Problem-MAX Finding the length of connected cells of 1s (regions) in an matrix of Os and 1s

int getVal(int (*a)[MAX], int newr, int newc, int low, int high) {
    if(newr < 0 || newc < 0 || newr >= low || newc >= high)
        return 0;
    return a[newr][newc];
}

void findMaxBlock(int a[][MAX], int r, int c, int low, int high, bool **visited,int size, int &maxSize)
{
    if(r >= low || c >= high)
        return;
    visited[r][c] = true;
    size++;
    if(maxSize < size)
        maxSize = size;
    // direction
    int direction[][2] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
    for(int i = 0;i<8;i++)
    {
        int newr = r + direction[i][0];
        int newc = c + direction[i][1];
        int val = getVal(a,newr,newc,low,high);
        if(val > 0 && !visited[newr][newc])
            findMaxBlock(a,newr,newc,low,high,visited,size,maxSize);
    }
    visited[r][c] = false;
}



int getMaxOnes(int a[][MAX],int rows,int cols)
{
    int maxSize = 0;
    bool **visited = new bool*[rows];
    for(int i = 0;i<rows;i++)
        visited[i] = new bool[cols];

    for(int i = 0;i<rows;i++)
    {
        for(int j = 0;j<cols;j++)
            if(a[i][j] == 1)
                findMaxBlock(a,i,j,rows,cols,visited,0,maxSize);
    }
    return maxSize;
}

int main() {
    // 5
    int a[5][5] = {{1,1,0,0,0},
                   {0,1,1,0,0},
                   {0,0,1,0,1},
                   {1,0,0,0,1},
                   {0,1,0,1,1}
    };
    // 6
    int M[][5] = {  {0,0,1,1,0},
                    {1,0,1,1,0},
                    {0,1,0,0,0},
                    {0,0,0,0,1}};

//    int a[][MAX] = {{1,0},{1,0}};
    cout<<getMaxOnes(M,5,5)<<endl;
    return 0;
}
