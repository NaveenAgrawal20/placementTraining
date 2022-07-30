#include<bits/stdc++.h>

using namespace std;

class Stack {
    char *arr;
    int top;
    int capacity;
public:
    Stack() {
        this->capacity = 1000000;
        arr = new char[capacity];
        top = -1;
    }

    int size() { return top + 1; }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == capacity - 1; }

    void push(char data) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        top++;
        arr[top] = data;
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    char pop() {
        if (isEmpty()) {
            cout << "UNDERFLOW\n";
            return -1;
        }
        return arr[top--];
    }
};

// precedence
int prec(char c) {
    switch (c) {
        case '^':
            return 3;
        case '/':
        case '*':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%';
}
void infixToPost(const string &s) {
    Stack st;
    char c;
    string postfix;
    int i = 0, siz = s.size();
    while (i < siz) {
        if(s[i] == '(')
            st.push('(');
        else if (s[i] == ')') {
            while ((c = st.pop()) != '(')
                postfix += c;
        }
        else if(isOperator(s[i]))
        {
            while(!st.isEmpty() && prec(st.peek()) >= prec(s[i]))
                postfix += st.pop();
            st.push(s[i]);
        }
        else{
            postfix += s[i];
        }
        i++;
    }
    while(!st.isEmpty())
        postfix += st.pop();

    cout<<postfix<<endl;
}

int main() {
    int T;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        infixToPost(s);
    }
    return 0;
}
/*
2
a+b*(c^d-e)^(f+g*h)-i
a*(b+c)/d
*/