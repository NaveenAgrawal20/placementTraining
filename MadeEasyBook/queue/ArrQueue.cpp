#include <iostream>
using namespace std;

typedef struct Queue{
    int capacity,size,front,rear;
    int *arr;
}QueueAr;

QueueAr* createQueue(int capacity)
{
    QueueAr *qu = new QueueAr();
    qu->capacity = capacity;
    qu->size = 0;
    qu->front = 0;
    qu->rear = capacity - 1;
    qu->arr = new int[capacity];
    return qu;
}
void enqueue(QueueAr *q,int data)
{
    if(q->size == q->capacity)
    {
        cout<<"Full ";
        return;
    }
    q->rear = (q->rear + 1)%q->capacity;
    q->arr[q->rear] = data;
    q->size++;
}
void dequeue(QueueAr *q){
    if(q->size == 0)
    {
        cout<<"Empty";
        return;
    }
    q->front = (q->front + 1)%q->capacity;
    q->size--;
}
void display(QueueAr *q){
    for(int i = 0;i<q->size;i++)
        cout<<q->arr[(q->front + i) % q->capacity]<<" ";
    cout<<"\n";
}
int main()
{
    QueueAr *q = createQueue(3);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    display(q);
    dequeue(q);
    dequeue(q);
    enqueue(q,4);
    enqueue(q,5);
    display(q);
    return 0;
}