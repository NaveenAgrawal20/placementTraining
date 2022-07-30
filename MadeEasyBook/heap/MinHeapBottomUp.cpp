#include<iostream>
using namespace std;
/*****
--------------Min Heap------------
******/
int size;

int parent(int i){
    return ((i-1)/2);
}
int left(int i){
    return (2*i+1);
}
int right(int i){
    return (2*i+2);
}
// Bottom up approach
void heapify_down(int heap[],int n,int i){
    int l = left(i);
    int r = right(i);
    int s = i;
    if(l<size && heap[l] < heap[i]){
        s = l;
    }
    if(r < size && heap[r] < heap[s]){
        s = r;
    }
    if(s != i){
        swap(heap[i],heap[s]);
        heapify_down(heap,n,s);
    }
}

void build_heap(int heap[],int n){
    for(int i = (size/2 - 1);i>=0;i--){
        heapify_down(heap,n,i);
    }
}
void print_heap(int heap[],int n){
    for(int i = 0;i<size;i++)
        cout<<heap[i]<<" ";
    cout<<"\n";
}

// Heap Sort
void heapSort(int heap[],int n){
    build_heap(heap,n);
    for(int i = n - 1;i>=1;i--){
        swap(heap[0],heap[i]);
        heapify_down(heap,i,0);
    }
}

int extractMin(int heap[]){
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify_down(heap,size,0);
    return root;
}

void decreaseKey(int heap[],int i,int val){
    heap[i] = val;
    while(i!=0 && heap[parent(i)] > heap[i]){
        swap(heap[parent(i)] ,heap[i]);
        i = parent(i);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int heap[n];
        for(int i = 0;i<n;i++){
            cin>>heap[i];
            size++;
        }
        build_heap(heap,n);
        print_heap(heap,n);
    }
}
/*
2
11
2 6 2 4 3 7 8 1 5 9 10
5
2 6 2 4 3
*/