#include<iostream>
#include <functional>
#include<vector>
using namespace std;

template<typename E,typename C>
void merge(vector<E> &in, vector<E> &out, const C& less, int b, int m)
{
    int i, j, k;
    i = b; // l1
    j = b + m; // l2
    k = b; //l1
    int n = in.size();
    int e1 = min(b + m, n); // u1
    int e2 = min(b + 2 * m, n); // u2
    while (i < e1 && j < e2)
    {
        if (less(in[i], in[j]))          //if(in[i] < in[j]) //less(lhs,rhs) => value true if lhs < rhs, false otherwise
            out[k++] = in[i++];
        else
            out[k++] = in[j++];
    }
    while (i < e1) {
        out[k++] = in[i++];
    }
    while (j < e2) {
        out[k++] = in[j++];
    }
}

template<typename E,typename C>
void mergeSort(vector<E>& vin,const C& less)
{
    int n = vin.size();
    typedef vector<E> vect; // small name for vector
    vect v1(vin);     // initial in vector
    vect v2(n);     // initial out vector
    vect* in = &v1;     //pointer to v1
    vect* out = &v2;    //pointer to v2
    for (int m = 1; m < n; m *= 2)
    {
        for (int b = 0; b < n; b += 2 * m)
        {
            merge(*in,*out,less,b,m);// merge sublists
        }
        swap(in, out);          // swap input with output
    }
    vin = *in; // copy sorted vector.
}

int main()
{
    int n;
    cout << "Enter number of elements ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cout << v[i]<<" ";
    }
    mergeSort(v,less<int>());
    cout << "\nAfter sort\n";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}