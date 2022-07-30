#include<bits/stdc++.h>

using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;
public:
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }

    int size() { return top + 1; }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == capacity - 1; }

    void push(int data) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        top++;
        arr[top] = data;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    int pop() {
        if (isEmpty()) {
            cout << "UNDERFLOW\n";
            return -1;
        }
        return arr[top--];
    }
};

int main()
{
    Stack s(5);
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