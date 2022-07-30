#include <iostream>
using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        data = node_data;
        next = nullptr;
    }
};

SinglyLinkedListNode *insertSortedNode(SinglyLinkedListNode *head, int value)
{

    SinglyLinkedListNode *newnode = new SinglyLinkedListNode(value);

    SinglyLinkedListNode *temp = head;
    if (temp == nullptr)
    {
        head = newnode;
        return head;
    }
    if (temp->data > value)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    SinglyLinkedListNode *prev;
    while (temp != nullptr && value >= temp->data)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = temp;
    return head;
}
void display(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, value;
        cin >> n;
        SinglyLinkedListNode *head;
        for (int i = 0; i < n; i++)
        {
            cin >> value;
            head = insertSortedNode(head, value);
            display(head);
        }
    }
    return 0;
}