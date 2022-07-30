#include<iostream>
#include<string>
#include<vector>

using namespace std;

int siz;

void heapify(char *heap, int i) {
    int s = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < siz && heap[l] < heap[i])
        s = l;
    if (r < siz && heap[r] < heap[s])
        s = r;
    if (s != i) {
        swap(heap[i], heap[s]);
        heapify(heap, s);
    }
}

int parent(int i) { return (i - 1) / 2; }

void insert_heap(char *heap, char ele) {
    heap[siz] = ele;
    int i = siz;
    siz++;
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

char extractMin(char *heap) {
    int root = heap[0];
    heap[0] = heap[siz - 1];
    siz--;
    heapify(heap, 0);
    return root;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int w,i;
        string str, s;
        cin >> str >> w;
        int n = str.length();
        char heap[n];
        for(i = 0;i<w;i++)
            insert_heap(heap,str[i]);

        while(i < n){
            s += extractMin(heap);
            insert_heap(heap,str[i]);
            i++;
        }
        while(siz){
            s += extractMin(heap);
        }
        cout << s << "\n";
    }
    return 0;
}
/*
2
jktfc 2
trnqf 3

Sample Output
jkfct
nqfrt
 */