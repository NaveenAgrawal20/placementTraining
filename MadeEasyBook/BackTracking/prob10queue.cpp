#include <iostream>
#include <stack>
#include <queue>
/*
 * given a queue = 11 12 13 14 15 16 17 18 19 20
 * print it like = 11 16 12 17 13 18 14 19 15 20
 * */
using namespace std;

template <typename T>
void showQ(queue<T> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\n";
}

int main() {
    queue<int> q;
    stack<int> s;
    for (int i = 11; i <= 20; i++)
        q.push(i);

    if (q.size() % 2 != 0)
        return 0;
    int halfsize = q.size() / 2;
    for(int i = 1;i<=halfsize;i++){
        s.push(q.front());q.pop();
    }
    //
    while(!s.empty()){
        q.push(s.top());s.pop();
    }
    for(int i = 1;i<=halfsize;i++){
        q.push(q.front());q.pop();
    }
    for(int i = 1;i<=halfsize;i++){
        s.push(q.front());q.pop();
    }
    while(!s.empty()){
        q.push(s.top());s.pop();
        q.push(q.front());q.pop();
    }
    // printing
    showQ(q);
    return 0;
}