#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p3 = NULL;
        while (p1 && p2)
        {
            sum = p1->val + p2->val;
            if (sum >= 10)
            {
                p3 = insert(p3, sum % 10);
                if(p1->next)
                    p1->next->val += 1;
                else if(p2->next)
                    p2->next->val += 1;
                else
                    p3 = insert(p3,1);
            }
            else
            {
                p3 = insert(p3, sum);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1)
        {
            if (p1->val >= 10)
            {
                p3 = insert(p3, p1->val % 10);
                if(p1->next)
                    p1->next->val += 1;
                else
                    p3 = insert(p3,1);
            }
            else
                p3 = insert(p3, p1->val);
            p1 = p1->next;
        }
        while (p2)
        {
            if (p2->val >= 10)
            {
                p3 = insert(p3, p2->val % 10);
                if(p2->next)
                    p2->next->val += 1;
                else
                    p3 = insert(p3,1);
            }
            else
                p3 = insert(p3, p2->val);
            p2 = p2->next;
        }
        p3 = reverseList(p3);
        return p3;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *ptr, *prev, *forward;
        ptr = head;
        prev = NULL;
        while (ptr != NULL)
        {
            forward = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = forward;
        }
        head = prev;
        return head;
    }
    ListNode* insert(ListNode* root, int key)
    {
        ListNode* newnode = new ListNode();
        newnode->val = key;
        newnode->next = nullptr;
        if(root == NULL)
            root = newnode;
        else{
            ListNode *p = root;
            while(p->next != nullptr)
                p = p->next;
            p->next = newnode;
        }
        return root;
    }
};