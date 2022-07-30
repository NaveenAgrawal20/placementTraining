#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *insert(Node *l3, int data)
{
    Node *newnode = new Node();
    newnode->data = data;
    newnode->next = NULL;
    if (l3 == NULL)
    {
        l3 = newnode;
        return l3;
    }
    Node *crawl = l3;
    while (crawl->next != NULL)
    {
        crawl = crawl->next;
    }
    crawl->next = newnode;
    return l3;
}
// given two list (l1,l2)
Node *merge(Node *l1, Node *l2)
{
    Node *l3 = NULL;
    if (l1 == NULL && l2 == NULL)
        return NULL;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            l3 = insert(l3, l1->data);
            l1 = l1->next;
        }
        else if (l1->data > l2->data)
        {
            l3 = insert(l3, l2->data);
            l2 = l2->next;
        }
        else
        {
            l3 = insert(l3, l1->data);
            l3 = insert(l3,l2->data);
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    // rem
    if(l1 != NULL)
    {
        l3->next = l1;
    }
    if(l2 != NULL)
        l3->next = l2;
    return l3;
}

int main()
{
    Node *start = new Node();
    return 0;
}