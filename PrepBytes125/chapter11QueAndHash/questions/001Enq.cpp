#include <iostream>
using namespace std;
class ArrQueue
{
    int front, rear;
    int size, capacity;
    int *arr;

public:
    explicit ArrQueue(int capacity)
    {
        this->capacity = capacity;
        front = 0;
        size = 0;
        rear = capacity - 1;
        arr = new int[capacity];
    }
    // enqueue
    void enqueue(int data)
    {
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
    }
    // dequeue
    void dequeue()
    {
        front = (front + 1) % capacity;
        size--;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[(front + i) % capacity] << " ";
        cout << "\n";
    }

    void reverseDisplay()
    {
        for (int i = size - 1; i >= 0; i--)
        {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    int T = 2;
    while (T--)
    {
        int n, data;
        cin >> n;
        ArrQueue *q = new ArrQueue(n);
        for (int i = 1; i <= n; i++)
        {
            cin >> data;
            q->enqueue(data);
        }
        q->reverseDisplay();
    }

    return 0;
}