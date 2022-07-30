#include <iostream>
#include <map>

using namespace std;

void display(map<int, int> map1)
// void display(unordered_set<int> s)
{
    map<int,int>::iterator itr;
    // unordered_set<int>::iterator itr;
    for (itr = map1.begin(); itr != map1.end(); itr++)
    {
        cout << itr->first <<":"<<itr->second<<"\n";
    }
    cout << endl;
}

int main()
{
    // name, roll
    map<int, int> map1;
    map1.insert(make_pair(2,10));
    map1[5] = 4;
    map1[1] = 6;
    display(map1);

    // find keys
    if(map1.find(5) != map1.end())
        cout<<"5 is there\n";
    if(map1.find(4) != map1.end())
        cout<<"4 is there\n";
    else
        cout<<"4 is NOT there\n";
    return 0;
}