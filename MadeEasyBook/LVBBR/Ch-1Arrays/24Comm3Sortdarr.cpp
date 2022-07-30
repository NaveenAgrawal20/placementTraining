#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> v;

void next_distinct(v& vec,int &point)
{
    do{
        point++;
    }while(point < vec.size() && vec[point-1] == vec[point]);
}

void printCommon3(v &v1, v &v2, v &v3)
{
    int i, j, k;
    i = j = k = 0;
    while (i < v1.size() && j < v2.size() && k < v3.size())
    {
        if (v1[i] == v2[j] && v2[j] == v3[k])
        {
            cout << v1[i] << ' ';
            next_distinct(v1,i);
            next_distinct(v2,j);
            next_distinct(v3,k);
        }
        else if (v1[i] < v2[j])
            next_distinct(v1,i);

        else if(v2[j] < v3[k])
            next_distinct(v2,j);

        else
            next_distinct(v3,k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // vector<int> v1 = {1, 5, 10, 20, 40, 80};
    // vector<int> v2 = {6, 7, 20, 80, 100};
    // vector<int> v3 = {3, 4, 15, 20, 30, 70, 80, 120};
    vector<int> v1= {1, 5, 5};
    vector<int> v2= {3, 4, 5, 5, 10};
    vector<int> v3= {5, 5, 10, 20};

    printCommon3(v1, v2, v3);

    return 0;
}