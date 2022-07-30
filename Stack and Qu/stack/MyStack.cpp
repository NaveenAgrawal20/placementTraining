#include <iostream>
using namespace std;

class StackEmpty
{
    const char *message;

public:
    StackEmpty(const char *st)
    {
        message = st;
    }
    const char *Gets()
    {
        return message;
    }
};
class StackFull
{
    const char *message;

public:
    StackFull(const char *st)
    {
        message = st;
    }
    const char *Gets()
    {
        return message;
    }
};

template <typename T>
class ArrayStack
{
    enum
    {
        DEF_CAPACITY = 100
    }; // default stack capacity
public:
    ArrayStack(int cap = DEF_CAPACITY);
    int size() const;
    bool isEmpty() const;
    const T &top();
    void push(const T &key);
    void pop();

private:
    T *arr; // array of stack element
    int capacity, t;
};

template <typename T>
ArrayStack<T>::ArrayStack(int cap) : arr(new T[cap]), t(-1), capacity(cap) {}

template <typename E>
int ArrayStack<E>::size() const
{
    return (t + 1);
} // number of items in the stack

template <typename E>
bool ArrayStack<E>::isEmpty() const
{
    return t < 0;
} // is the stack empty?

template <typename E>
const E &ArrayStack<E>::top()
{
    if (isEmpty())
        throw StackEmpty("Top of Empty Stack");
    return arr[t];
}

template <typename E>
void ArrayStack<E>::push(const E &e)
{
    if (t == capacity)
    {
        throw StackFull("Stack OVERFLOW");
    }
    arr[++t] = e;
}
template <typename E>
void ArrayStack<E>::pop()
{
    if (isEmpty())
        throw StackEmpty("Pop from empty Stack");
    --t;
}

int main()
{
    ArrayStack<int> A; // A = [ ], size = 0
    A.push(7);         // A = [7*], size = 1
    A.push(13);        // A = [7, 13*], size = 2
    cout << A.top() << endl;
    A.pop();                 // A = [7*], outputs: 13
    A.push(9);               // A = [7, 9*], size = 2
    cout << A.top() << endl; // A = [7, 9*], outputs: 9
    cout << A.top() << endl;
    A.pop();                  // A = [7*], outputs: 9
    ArrayStack<string> B(10); // B = [ ], size = 0
    B.push("Bob");            // B = [Bob*], size = 1
    B.push("Alice");          // B = [Bob, Alice*], size = 2
    cout << B.top() << endl;
    B.pop();       // B = [Bob*], outputs: Alice
    B.push("Eve"); // B = [Bob, Eve*], size = 2
    return 0;
}