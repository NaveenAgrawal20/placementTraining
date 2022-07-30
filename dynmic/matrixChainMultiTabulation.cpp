/*
 * Created By Naveen
 * Created on 2021
 * Copyright © 2021
 */

#include<iostream>
#include <climits>
using namespace std;
/*
* MATRIX CHAIN MULTIPLICATION using TABULATION
* We start from 1 index as formula has d[i-1]
* thus for simplicity of program 
*
**** FORMULA => cost[i][j] := min{cost[i][k] + cost[k+1][j] + d[i-1]*d[k]*d[j]} ,where i<=k<j;
*/
void matrixChainMulti(int d[],int n)
{
    int i, j, k, min;
    //int c[n][n]; // cost Matrix // as we dont use 0th row and 0th column. // if used size must be [n-1][n-1] as d.size = n;
    int c[n][n];
    //int c[10][10];
    // for a matrix that is multiplyed by itself is min = 0
    for (i = 1; i < n; i++) {
        c[i][i] = 0;
    }
    // l for traversing along chain length
    int cost;
    for (int l = 2; l <= n-1; l++) 
    {
        for (i = 1; i <= n-l; i++)
        {
            j = i + l-1;
            min = INT_MAX;
            for (k = i; k <= j-1; k++)          // as i<=k<j
            {
                cost = c[i][k] + c[k + 1][j] + d[i-1] * d[k] * d[j];
                if (min > cost)
                    min = cost;
                c[i][j] = min;
            }
        }
    }
    cout << "Min multiplication required are = " << c[1][n - 1] << endl;
}

int main()
{
    int n;
    cout<<"Enter num of matrix + 1 ";
    cin>>n;
    int d[n];
    cout<<"Enter chain of matrix ";// matrix chain
    for(int i = 0;i<n;i++)
        cin>>d[i];    
    matrixChainMulti(d, n);
    return 0;
}
/*
5
40 20 30 10 30
Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

Input: p[] = {10, 20, 30, 40, 30} 
Output: 30000 
There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

Input: p[] = {10, 20, 30}  
Output: 6000  
There are only two matrices of dimensions 10x20 and 20x30. So there 
is only one way to multiply the matrices, cost of which is 10*20*30
*/