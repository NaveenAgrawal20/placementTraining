#include <iostream>
#include "ArrQueue.h"
using namespace std;


int main()
{
    ArrQueue q1 = ArrQueue(3);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.display();
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    q1.enqueue(4);
    q1.enqueue(5);
    q1.display();

}