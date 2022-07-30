#include <iostream>
#include "SllinkedList.h"

using namespace std;

void display(SllNode *head) {
    SllNode *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

bool hasKnodes(SllNode *head, int k) {
    int i;
    for (i = 0; i < k && head; i++)
        head = head->next;
    return i == k;
}

// Reverse K node
SllNode *reverseKNodes(SllNode *head, int k) {
    SllNode *curr, *prevTail, *prevCur;
    // current
    curr = head;
    // lastNode before reverse;
    prevCur = head;
    // lastNode after reverse;
    prevTail = nullptr;
    while (curr != nullptr && hasKnodes(curr, k)) {
        // loop for reversing k nodes
        int count = k;
        SllNode *tail = nullptr;

        while (curr != nullptr && count > 0) {
            SllNode *next = curr->next;
            curr->next = tail;
            tail = curr;
            curr = next;
            count--;
        }

        // now, k nodes are reversed
        if (prevTail != nullptr) {
            prevTail->next = tail;
        } else {// only updated K nodes, update head point to kth node;
            head = tail;
        }
        //
        prevTail = prevCur;
        prevCur = curr;
    }
    if(curr)
        prevTail->next = curr;
    return head;
}

int main() {
    Sll *ll1 = new Sll();
    int n;
    cout << "enter numbers to insert into list, -1 to stop : ";

    while (1) {
        cin >> n;
        if (n == -1)
            break;
        ll1->insert_node_AtEnd(n);
    }
    display(ll1->head);
    int k;
    cin >> k;
    ll1->head = reverseKNodes(ll1->head, k);
    display(ll1->head);

}
/*
1
2
3
4
5
6
7
8
9
10
-1
4
*/