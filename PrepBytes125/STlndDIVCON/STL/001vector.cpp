#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myCompare(int x, int y)
{
    return x > y;
}

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), myCompare);
    display(v);

    vector<int>::iterator iter;
    iter = v.begin() + 3;
    v.insert(iter, 55);
    display(v);

    v.erase(v.begin(),v.begin()+2);
    display(v);

    return 0;
}
/*
8 9 1 4 12
*/