#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
    Node *top;
public:
    Stack() {
        this->top = nullptr;
    }

    bool isEmpty() { return top == nullptr; }

    void push(int data) {
        Node *newnode = new Node(data);
        newnode->next = top;
        top = newnode;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }
    int pop(){
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return -1;
        }
        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<s.peek()<<endl;
    cout<<"Popped = "<<s.pop()<<endl;
    cout<<s.peek()<<endl;
}