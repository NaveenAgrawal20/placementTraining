#include <iostream>
#include <set>
#include<unordered_set>
using namespace std;

// void display(set<int> s)
void display(unordered_set<int> s)
{
    // set<int>::iterator itr;
    unordered_set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

int main()
{
    // set<int> s;
    unordered_set<int> s;
    s.insert(41);
    s.insert(2);
    s.insert(100);
    s.insert(50);
    s.insert(2);
    display(s);
    s.erase(2);
    display(s);
    cout << s.size() << endl;

    if (s.find(50) != s.end())
        cout << "50 is there \n";

    // set<int>::iterator itr = s.find(50);
    unordered_set<int>::iterator itr = s.find(50);
    cout<<*itr<<endl;

    return 0;
}