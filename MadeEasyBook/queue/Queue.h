//
// Created by priya on 7/15/2021.
//

#ifndef MADEEASYBOOK_QUEUE_H
#define MADEEASYBOOK_QUEUE_H

class Node {
public:
    int data;
    Node *next;
    explicit Node(int data) : data(data), next(nullptr) {};
};

class Queue {
    public:
        Node *front,*rear;
    Queue(){
        rear = front = nullptr;
    }
    void enqueue(int data)
    {
        Node *newnode = new Node(data);
        if(rear == nullptr)
        {
            front = rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = newnode;
    }
    int dequeue(){
        if(front == nullptr){
            std::cout<<"Empty\n";
            return INT_MIN;
        }
        Node *temp = front;
        int x = front->data;
        front = front->next;
        if(front == nullptr)
        {
            front = rear = nullptr;
        }
        free(temp);
        return x;
    }
    void display(){
        Node *ptr = this->front;
        while(ptr != nullptr){
            std::cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        std::cout<<"\n";
    }
};


#endif //MADEEASYBOOK_QUEUE_H
