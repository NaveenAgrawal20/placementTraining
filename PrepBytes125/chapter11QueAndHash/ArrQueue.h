//
// Created by priya on 7/15/2021.
//

#ifndef MADEEASYBOOK_ARRQUEUE_H
#define MADEEASYBOOK_ARRQUEUE_H


class ArrQueue {
    int front, rear;
    int size, capacity;
    int *arr;
public:
    explicit ArrQueue(int capacity) {
        this->capacity = capacity;
        front = 0;
        size = 0;
        rear = capacity - 1;
        arr = new int[capacity];
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    // enqueue
    void enqueue(int data) {
        if (isFull()) {
            std::cout << "Queue is Full";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
    }
    // dequeue
    int dequeue(){
        if(isEmpty()){
            std::cout << "Queue is Empty";
            return INT_MIN;
        }
        int data = arr[rear];
        front = (front + 1) % capacity;
        size--;
        return data;
    }

    // get front element
    int frontEle()
    {
        if(isEmpty()){
            std::cout<<"Queue is Empty\n";
            return INT_MIN;
        }
        return arr[front];
    }
    // get front element
    int getEle(){
        if(isEmpty()){
            std::cout<<"Queue is Empty\n";
            return INT_MIN;
        }
        return arr[rear];
    }
    void display(){
        for(int i = 0;i<size;i++)
            std::cout<<arr[(front+i)%capacity]<<" ";
        std::cout<<"\n";
    }
};


#endif //MADEEASYBOOK_ARRQUEUE_H
