#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

bool myCompare(int x, int y)
{
    return x > y;
}

void display(list<int> l)
{
    list<int>::iterator iter;
    for(iter = l.begin();iter != l.end();iter++){
        cout<<*iter<<endl;
    }
    cout << endl;
}

int main()
{
    list<int> l;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }
    l.push_front(89);
    display(l);



    return 0;
}
/*
8 9 1 4 12
*/