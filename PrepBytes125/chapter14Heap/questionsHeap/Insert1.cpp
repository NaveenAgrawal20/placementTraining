#include <iostream>
using namespace std;
void printHeap(int *heap,int n){
    for (int i = 0; i < n; i++)
        cout<<heap[i]<<" ";
    cout<<"\n";
}
int parent(int i){
    return (i - 1)/2;
}

/*1 */
void insertHeap(int *heap,int ele,int i){
    heap[i] = ele;
    while (i != 0 && heap[i] < heap[parent(i)])
    {
        swap(heap[i],heap[parent(i)]);
        i = parent(i);
    }    
}
/*END*/
/*2 OPHEAP*/
int heapsize;
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}

void heapifyDown(int *heap,int siz,int i){
    int s = i, l = left(i),r = right(i);
    if (l < siz && heap[i] > heap[l]){
        s = l;
    }
    if (r < siz && heap[s] > heap[r]){
        s = r;
    }
    if (s != i){
        swap(heap[i],heap[s]);
        heapifyDown(heap,siz,s);
    }
}

int extractMin(int *heap){
    int root = heap[0];
    heap[0] = heap[heapsize - 1];
    heapsize--;
    heapifyDown(heap,heapsize,0);
    return root;
}

void decreaseKey(int heap[],int i,int val){
    heap[i] = val;
    while(i!=0 && heap[parent(i)] > heap[i]){
        swap(heap[parent(i)] ,heap[i]);
        i = parent(i);
    }
}
void deleteKey(int *heap,int i){
    decreaseKey(heap,i,INT_MIN);
    extractMin(heap);
}
/*END*/

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, ele,k;
        cin>>n >> k;
        k = k - 1;
        heapsize = n;
        int heap[n];
        for (int i = 0; i < n; i++)
        {
            cin>>ele;
            insertHeap(heap,ele,i);
        }
        deleteKey(heap,k);
        printHeap(heap,heapsize);
    }
    return 0;
}
