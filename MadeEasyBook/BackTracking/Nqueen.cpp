#include<iostream>

using namespace std;
#define n 4

bool isSafe(int board[][n], int i, int row) {
    // rows
    for(int j = row;j>=0;--j){
        if(board[j][i] == 1)
            return false;
    }
    // columns
    for (int j = i; j >= 0; --j)
        if(board[row][j] == 1) {
            return false;
        }
    // diagonal
    for(int j = i,k = row;j>=0 && k >= 0;--j,--k){
        if(board[k][j] == 1)
            return false;
    }
    return true;
}

int solve(int board[][n], int row) {
    if (row == n)
        return 1;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, row)) {
            board[row][i] = 1;
            if (solve(board, row + 1))
                return 1;
        }
        board[row][i] = 0;
    }
    return 0;
}


int main() {
    int board[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = 0;
        }
    }
    solve(board,0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}