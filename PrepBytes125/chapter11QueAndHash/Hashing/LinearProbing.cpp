#include<iostream>

using namespace std;
#define MAXCAP 10

struct slot {
    int key, data;
};
struct hashTable_slot {
    int flag;
    /*flag = 0 :record does not exist
     flag = 1 : record exist
     */
    slot *record;
};

hashTable_slot arr[MAXCAP];

void initializeHashTable() {
    for (auto &i : arr) {
        i.flag = 0;
        i.record = nullptr;
    }
}

void insert(int key, int value) {
    int index = key % MAXCAP;
    // creating new item
    slot *item = new slot();
    item->key = key;
    item->data = value;

    int i = index;
    while (arr[i].flag == 1) {
        if (arr[i].record->key == key) {
            cout << "Duplicate key is not allowed\n";
            return;
        }
        i = (i + 1) % MAXCAP;
        if (i == index) {
            cout << "HashTable is full\n";
            return;
        }
    }
    arr[i].flag = 1;
    arr[i].record = item;
}

bool searchElement(int key)
{
    int index = key % MAXCAP;
    int i = index;
    while(arr[i].flag != 0){
        if(arr[i].record->key == key)
            return true;
        i = (i + 1) % MAXCAP;
        if(i == index)
            return false;
    }
    return false;
}
void display(){
    for(int i = 0;i<MAXCAP;i++){
        slot *crawl = arr[i].record;
        if(crawl == nullptr){
            cout<<"hashTable["<<i<<"] has no elements\n";
        }
        else{
            cout<<"hashTable["<<i<<"] has elements\n";
            cout<<"key = "<<crawl->key<<" and value = "<<crawl->data<<"\n";
        }
    }
}
int main() {
    initializeHashTable();
    int key,val;
    for(int i = 0;i<10;i++){
        cin>>key>>val;
        insert(key,val);
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