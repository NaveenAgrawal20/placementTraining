/*
 * Created By Naveen
 * Created on 2021
 * Copyright © 2021
 */

#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> v)
{
    for (int i = 1; i < v.size(); i++)
    {
        for (int j = 1; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

void matrixChainM(vector<int> &v)
{
    int i, j, k, l, n = v.size();
    int min, cost;
    // init 2D vector
    vector<vector<int>> c;
    for (i = 0; i < n; i++) // starts from index 1
    {
        vector<int> v1(n, INT_MAX);
        c.push_back(v1);
    }
    for (i = 0; i < n; i++)
        c[i][i] = 0;
    //display(c);
    for (l = 2; l <= n - 1; l++)
    {
        for (i = 1; i <= n - l; i++)
        {
            j = i + l - 1;
            min = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                cost = c[i][k] + c[k + 1][j] + v[i - 1] * v[k] * v[j];
                if (min > cost)
                {
                    min = cost;
                }
                c[i][j] = min;
            }
        }
    }
    cout << "Min multiplication = " << c[1][n - 1];
}

int main()
{

    int n, e;
    vector<int> v;
    cout << "Enter num of matrix + 1";
    cin >> n;
    cout << "Enter matrix chain ";
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        v.push_back(e);
    }
    matrixChainM(v);
}
/*
5
40 20 30 10 30
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