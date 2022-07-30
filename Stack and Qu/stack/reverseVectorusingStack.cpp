// Program to Reverse a VECTOR using STACK

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

template<typename E>
void reverse(vector<E> &v)
{
    stack<E> stck;
    for(auto i:v){
        stck.push(i);
    }
    for(int i =0;i<v.size();i++){
        v[i] = stck.top();
        stck.pop();
    }
}

int main()
{
    vector<char> vchar{'a','b','c'};
    for(auto vi:vchar)
        cout<<vi<<" ";
    cout<<"\nAfter reversing \n";
    reverse(vchar);
    for(auto vi:vchar)
        cout<<vi<<" ";
    return 0;
}