//
// Created by priya on 7/14/2021.
//
#include <stack>
using namespace std;
#ifndef MADEEASYBOOK_SLINKEDLIST_H
#define MADEEASYBOOK_SLINKEDLIST_H


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
};

#endif //MADEEASYBOOK_SLINKEDLIST_H
