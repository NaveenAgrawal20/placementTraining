#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

// given two list (l1,l2)
Node *merge(Node *l1, Node *l2)
{
    if (l1 == NULL && l2 == NULL)
        return NULL;

    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    
    Node *l3 = l1;
    if(l1->data > l2->data)
    {
        l3 =  l2;
        l2 = l2->next;
    }
    else
    {
        l1 = l1->next;
    }
    Node* crawl = l3;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            crawl->next = l1;
            l1 = l1->next;
        }
        else
        {
            crawl->next = l2;
            l2 = l2->next;
        }
        crawl = crawl->next;
    }

    // rem
    if(l1 != NULL)
        crawl->next = l1;

    if(l2 != NULL)
        crawl->next = l2;
    return l3;
}

int main()
{
    Node *start = new Node();
    return 0;
}