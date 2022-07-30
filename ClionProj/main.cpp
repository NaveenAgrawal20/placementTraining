#include<bits/stdc++.h>

using namespace std;

class SllNode {
public:
    int data;
    SllNode *next;

    SllNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Sll {
public:
    SllNode *head;

    Sll() {
        this->head = nullptr;
    }

    void insert_node_AtBeggining(int data) {
        SllNode *newnode = new SllNode(data);
        newnode->next = this->head;
        this->head = newnode;
    }

    void insert_node_AtEnd(int data) {
        SllNode *p = this->head;
        if (p == nullptr)
            this->head = new SllNode(data);
        else {
            while (p->next != nullptr)
                p = p->next;
            p->next = new SllNode(data);
        }
    }

    bool isPalindrome() {
        stack<int> s;
        SllNode *ptr = head;
        while (ptr != nullptr) {
            s.push(ptr->data);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr != nullptr) {
            if (ptr->data != s.top()) {
                return false;
            }
            s.pop();
            ptr = ptr->next;
        }
        return true;
    }

    void insert_node_Atmiddle(int data, int pos) {
        SllNode *newnode = new SllNode(data);
        SllNode *temp = this->head;
        if (temp == nullptr)
            insert_node_AtBeggining(data);
        else {
            if (pos == 1)
                insert_node_AtBeggining(data);
            else {
                int count = 2;
                while (count < pos) {
                    temp = temp->next;
                    count++;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
    }


    SllNode *insertSortedNode(int value) {
        SllNode *newnode = new SllNode(value);
        SllNode *temp = head;
        if (temp == nullptr) {
            head = newnode;
            return head;
        }
        if (temp->data > value) {
            newnode->next = head;
            head = newnode;
            return head;
        }
        SllNode *prev;
        while (temp != nullptr && value >= temp->data) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = newnode;
        newnode->next = temp;
        return head;
    }

    SllNode *reverse() {
        SllNode *prev = nullptr, *after, *curr = head;
        if (head == nullptr)
            return head;
        while (curr != nullptr) {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }

    void delete_atBegin() {
        if (this->head == nullptr)
            return;
        SllNode *temp = this->head;
        this->head = temp->next;
        delete temp;
    }

    void delete_atEnd() {
        if (this->head == nullptr)
            return;
        SllNode *temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next->next;
        temp->next = nullptr;
    }

    void delete_atMid(int pos) {
        SllNode *temp = this->head;
        if (temp == nullptr)
            return;
        else {
            if (pos == 1) {
                SllNode *deleteNode = this->head;
                this->head = this->head->next;
                delete deleteNode;
            } else {
                int count = 2;
                while (count < pos) {
                    temp = temp->next;
                    count++;
                }
                SllNode *deletedNode = temp->next;
                temp->next = deletedNode->next;
                delete deletedNode;
            }
        }
    }

    SllNode *addOne() {
        stack<int> s;
        SllNode *ptr = head;
        while (ptr != nullptr) {
            s.push(ptr->data);
            ptr = ptr->next;
        }
        // insert at begining
        head = nullptr;
        int carry = 0, newData = s.top() + 1;
        while (!s.empty()) {
            carry = newData / 10;
            SllNode *newnode = new SllNode(newData % 10);
            newnode->next = head;
            head = newnode;
            s.pop();
            if(s.empty())
                break;
            newData = s.top() + carry;
        }
        if (carry != 0) {
            SllNode *newnode = new SllNode(carry);
            newnode->next = head;
            head = newnode;
        }
        return head;
    }
};

void display(SllNode *head) {
    SllNode *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Sll *ll1 = new Sll();
    ll1->head = ll1->insertSortedNode(2);
    ll1->head = ll1->insertSortedNode(4);
    ll1->head = ll1->insertSortedNode(3);
    ll1->head = ll1->insertSortedNode(5);
    ll1->head = ll1->insertSortedNode(1);
    display(ll1->head);
//    cout << ll1->isPalindrome() << endl;
    ll1->head = ll1->addOne();
    display(ll1->head);

    Sll *ll2 = new Sll();
    ll2->insert_node_AtEnd(9);
    ll2->insert_node_AtEnd(9);
    ll2->insert_node_AtEnd(9);
    ll2->insert_node_AtEnd(9);
    display(ll2->head);
    ll2->head = ll2->addOne();
    display(ll2->head);
//    cout << ll2->isPalindrome() << endl;
    //    ll1->insert_node_Atmiddle(10, 1);
//    ll1->insert_node_Atmiddle(5, 1);
//    ll1->insert_node_Atmiddle(20, 3);
//    ll1->insert_node_Atmiddle(15, 3);
//    ll1->delete_atMid(1);

//    display(ll1->head);
//    ll2.insert_node_AtBeggining(5);
//    ll2.insert_node_AtEnd(15);
//    display(ll2.head);
    return 0;
}