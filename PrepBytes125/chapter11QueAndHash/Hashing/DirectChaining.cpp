#include<iostream>

using namespace std;

//linked list node
struct node {
    int key;
    int data;
    struct node *next;
};

// for storing linked list at each index of hash table
struct hashIndexList {
    struct node *head;
    struct node *tail; // so we dont need to traverse whole ll
};
hashIndexList *arr;

int size = 0; // current num of elements in hashtable
int maxCap = 10; // max capacity
// Insert into hash slot
void insert(int key, int value) {
    int index = key % maxCap;
    // create a new item
    node *item = new node();
    item->data = value;
    item->key = key;
    item->next = nullptr;
    // getting the current list present at index
    node *list = arr[index].head;

    // if empty
    if (list == nullptr) {
        arr[index].head = item;
        arr[index].tail = item;
    } else {
        item->next = arr[index].head;
        arr[index].head = item;
    }
}

bool searchElement(int key) {
    int index = key % maxCap;
    node *list = arr[index].head;
    while (list != nullptr) {
        if (list->key == key)
            return true;
        list = list->next;
    }
    return false;
}

void display() {
    for (int i = 0; i < maxCap; i++) {
        node *list = arr[i].head;
        if (list == nullptr)
            cout << "arr[" << i << "] has no elements\n";
        else {
            cout <<"arr[" << i << "] has elements\n";
            while (list != nullptr) {
                cout << "Key = " << list->key << ", value = " << list->data << "\n";
                list = list->next;
            }
        }
    }
}

void initializeHashTable() {
    for (int i = 0; i < maxCap; i++) {
        arr[i].head = nullptr;
        arr[i].tail = nullptr;
    }
}

int main() {
    arr = (hashIndexList *) malloc(maxCap * sizeof(hashIndexList));
    initializeHashTable();
    int key, value;
    for (int i = 0; i < 10; i++) {
        cin >> key >> value;
        insert(key, value);
    }
    display();
    cout<<(searchElement(1321) ? "True" : "False")<<"\n";
    return 0;
}
/*
121 132
1321 412
454 45
555 345
54 213
615 142
431 123
5418 99
999 87
23 489
 */