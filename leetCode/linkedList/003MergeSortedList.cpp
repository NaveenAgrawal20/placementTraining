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
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *l3 = nullptr;
    if (l1 == nullptr && l2 == nullptr)
    {
        return nullptr;
    }
    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val > l2->val)
        {
            l3 = insert(l3, l2->val);
            l2 = l2->next;
        }
        else if (l1->val < l2->val){
            l3 = insert(l3,l1->val); 
            l1 = l1->next;
        }
        else{
            l3 = insert(l3,l1->val);
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    // Remainig
    while(l1 != nullptr){
        l3 = insert(l3,l1->val);
        l1 = l1->next;
    }
    while(l2 != nullptr){
        l3 = insert(l3,l2->val);
        l2 = l2->next;
    }
    return l3;
}

ListNode *insert(ListNode *l3, int val)
{
    // if initially empty
    ListNode *newnode = new ListNode(val);
    if (l3 == NULL)
    {
        l3 = newnode;
        return l3;
    }
    // at end
    else
    {
        ListNode *crawler = l3;
        while(crawler->next != nullptr){
            crawler = crawler->next;
        }
        crawler->next = newnode;
        return l3;
    }
}
int main()
{

    return 0;
}