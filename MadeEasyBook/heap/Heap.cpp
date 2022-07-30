#include<iostream>
using namespace std;
#define MINHP -1
#define MAXHP 1

class Heap{
public:
    int *arr;
    int size;
    int capacity;
    int heap_type;
    Heap(int n,int typeHeap){
        this->arr = new int[n];
        this->capacity = n;
        this->size = n;
        this->heap_type = typeHeap;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    void heapify_down(int i){
        int l,r;
        l = left(i);
        r = right(i);
        int idxMin = i;
        if(l < size && arr[l] < arr[i] ){
            idxMin = l;
        }
        if(r < size && arr[r] < arr[idxMin]){
            idxMin = r;
        }
        if(i != idxMin){
            swap(arr[i],arr[idxMin]);
            heapify_down(idxMin);
        }
    }
    void buildHeap(){
        for(int i = (size/2 - 1);i>=0;i--){
            heapify_down(i);
        }
    }
    void heapSort(){
        buildHeap();
        int oldSize = this->size;
        for(int i = oldSize - 1;i>=1;i--){
            swap(arr[0],arr[i]);
            this->size--;
            heapify_down(0);
        }
        this->size = oldSize;
    }
    void printHeap(){
        for(int i = 0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
    }
};

int main(){
    int T;
//    cin>>T;
    T = 2;
    while(T--){
        int n;
        cin>>n;
        // min heap
        Heap *heap = new Heap(n,MINHP);
        for(int i = 0;i<n;i++){
            cin>>heap->arr[i];
        }
//        heap->buildHeap();
        heap->heapSort();
        heap->printHeap();
    }
    return 0;
}
/*
5
2 6 2 4 3
2 3 2 4 6
11
2 6 2 4 3 7 8 1 5 9 10
1 2 2 4 3 7 8 6 5 9 10
 */