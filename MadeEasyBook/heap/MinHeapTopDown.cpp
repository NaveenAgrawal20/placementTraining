#include<iostream>
using namespace std;
/*
 * Min Heap - Top Down (If have to insert one by one )
 * */
int parent(int i){
    return (i-1)/2;
}
void print_heap(int heap[],int n){
    for(int i = 0;i<n;i++)
        cout<<heap[i]<<" ";
    cout<<"\n";
}
void insert_heap(int heap[],int i,int ele){
    heap[i] = ele;
    while(i != 0 && heap[parent(i)] > heap[i]){
        swap(heap[parent(i)],heap[i]);
        i = parent(i);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,ele;
        cin>>n;
        int heap[n];
        for(int i = 0;i<n;i++){
            cin>>ele;
            insert_heap(heap,i,ele);
        }
        print_heap(heap,n);
    }
    return 0;
}

/*
2
11
2 6 2 4 3 7 8 1 5 9 10
5
2 6 2 4 3
*/