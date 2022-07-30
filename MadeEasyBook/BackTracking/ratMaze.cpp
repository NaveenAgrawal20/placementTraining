#include<iostream>
using namespace std;
#define n 4

int isValid(int x,int y,int maze[][n]){
    if (x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0){
        return 0;
    }
    return 1;
}

int solve(int maze[][n],int x, int y, int solved[][n]){
    if(x == n-1 && y == n-1)    /* Reached Destination */
    {
        solved[x][y] = 1;
        return 1;
    }
    if(isValid(x,y,maze) == 1){
        solved[x][y] = 1;
        if(solve(maze,x+1,y,solved) == 1)
            return 1;
        if(solve(maze,x,y+1,solved) == 1)
            return 1;
        solved[x][y] = 0;
        return 0;
    }
    return 0;
}


int main(){
    int maze[n][n] = {{1,0,0,0},
                      {1,1,0,1},
                      {0,1,0,0},
                      {1,1,1,1}};
    int solved[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            solved[i][j] = 0;
        }
    }
    solve(maze,0,0,solved);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<solved[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}