#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    queue<int> q;
    s.push(4);
    s.push(5);
    s.push(-2);
    s.push(-3);
    s.push(11);
    s.push(10);
    s.push(5);
    s.push(6);
    s.push(20); // top and idx = 8
    // reversing elements // such that top becomes lower most
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    while (!q.empty()) {
        s.push(q.front());
        q.pop(); // deletion is from front
    }
    int n, m;
    while (!s.empty()) {
        n = s.top();
        s.pop();
        if (!s.empty()) {
            // if need pair. We can also use other stl like vector
            q.push(n);
            m = s.top();
            s.pop();
            q.push(m);
            if (abs(n - m) != 1) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes Pair\nand the pairs:\t";
    string str;
    while(!q.empty())
    {
        str += "("+to_string(q.front())+",";
        q.pop();
        str += to_string(q.front())+"), ";
        q.pop();
    }
    str.pop_back(); // remove last ','
    str.pop_back(); // remove last ' ' <space>
    cout<<str;
    return 0;
}