#include<iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.display();
    cout<<qu.dequeue()<<"\n";
    cout<<qu.dequeue()<<"\n";
    qu.enqueue(4);
    qu.enqueue(5);
    qu.display();
    return 0;
}
