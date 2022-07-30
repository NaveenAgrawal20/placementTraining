#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;
unordered_map<int, int> heapCode; // array of index
unordered_map<int, bool> colorBool;
int *colorHeapArray;
vector<pair<int, int>> colorCode; /* array after sorting with color as index <element,colorCode(0,1,2)>*/

class MinHeap
{
    int *heapArr;
    int capacity, heap_size;

public:
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        heapArr = new int[cap];
        colorHeapArray = new int[cap];
    }
    void MinHeapify(int i)
    {
        int l, r;
        l = left(i);
        r = right(i);
        int idxMin = i;
        if (l < heap_size && heapArr[l] < heapArr[i])
        {
            idxMin = l;
        }
        if (r < heap_size && heapArr[r] < heapArr[idxMin])
        {
            idxMin = r;
        }
        if (i != idxMin)
        {
            swap(heapArr[i], heapArr[idxMin]);
            swap(heapCode[colorHeapArray[i]], heapCode[colorHeapArray[idxMin]]);
            swap(colorHeapArray[i], colorHeapArray[idxMin]);
            MinHeapify(idxMin);
        }
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    int heap_heapSize() { return heap_size; }

    void insertKey(int k, int index)
    {
        if (heap_size == capacity)
        {
            cout << "cant insert\n";
            return;
        }
        heap_size++;
        int i = heap_size - 1;
        heapArr[i] = k;

        int ind = i;

        while (i != 0 && heapArr[parent(i)] > heapArr[i])
        {
            swap(heapArr[i], heapArr[parent(i)]);
            ind = i;
            i = parent(i);
        }
        colorHeapArray[ind] = colorCode[index].second;
        heapCode[colorCode[index].second] = ind;
        colorBool[colorCode[index].second] = true;
    }
    void decreaseKey(int i, int new_val)
    {
        heapArr[i] = new_val;
        while (i != 0 && heapArr[parent(i)] > heapArr[i])
        {
            int ind = parent(i);
            swap(heapArr[i], heapArr[ind]);
            swap(colorHeapArray[i], colorHeapArray[ind]);
            heapCode[colorHeapArray[i]] = i;
            i = parent(i);
        }
    }
    int extractMin()
    {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return heapArr[0];
        }
        int root = heapArr[0];
        heapArr[0] = heapArr[heap_size - 1];
        colorHeapArray[0] = colorHeapArray[heap_size - 1];
        heapCode[colorHeapArray[heap_size - 1]] = 0;
        heap_size--;
        MinHeapify(0);
        return root;
    }

    int extractMinVal(){return heapArr[0];}

    void deleteKey(int i){
        decreaseKey(i,INT_MIN);
        extractMin();
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        heapCode.clear();
        colorCode.clear();
        colorBool.clear();
        int n, i,m;
        cin >> n >>m;
        int a[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        int k = 0;
        for (i = 0;i<n;i++)
        {
            colorCode.emplace_back(a[i],k);
            k = (k+1)%m;
            colorBool[k] = false;
        }
        sort(colorCode.begin(), colorCode.end());
        MinHeap mh(m);
        int max = 0, min = INT_MAX;
        for(int i = 0;i<n;++i)
        {
            if(colorBool[colorCode[i].second] || mh.heap_heapSize() == m)
            {
                int indexVal = heapCode[colorCode[i].second];
                mh.deleteKey(indexVal);
            }
            mh.insertKey(colorCode[i].first,i);
            max = colorCode[i].first;
            if (mh.heap_heapSize() == m){
                int value = mh.extractMinVal();
                if (min > (max - value))
                    min = max - value;
            }
        }
        cout<<min<<"\n";
    }

    return 0;
}
/*
1
8 3
10 20 15 30 28 35 40 45
*/