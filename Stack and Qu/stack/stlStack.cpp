#include<iostream>
#include<stack>
using namespace std;
/*
size(): Return the number of elements in the stack.
empty(): Return true if the stack is empty and false otherwise.
push(e): Push e onto the top of the stack.
pop(): Pop the element at the top of the stack.
top(): Return a reference to the element at the top of the stack.

There is one significant difference between the STL implementation and our
own definitions of the stack operations. In the STL implementation, the result of
applying either of the operations top or pop to an empty stack is undefined. In
particular, no exception is thrown. Even though no exception is thrown, it may
very likely result in your program aborting. Thus, it is up to the programmer to be
sure that no such illegal accesses are attempted.*/
int main()
{
    // int p;
    stack<int> myStack;
    myStack.push(10);
    // myStack.push(20);
    // myStack.push(40);
    printf("Size is %d and top ele is %d",myStack.size(),myStack.top()); //output:Size is 3 and top ele is 40
    myStack.pop();
    // here no exception is thrown BUT IT SHOULD in MOST CASES
    printf("Size is %d and top ele is %d",myStack.size(),myStack.top()); 
    return 0;
}