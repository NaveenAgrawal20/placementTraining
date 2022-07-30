#include<iostream>
#include <functional>
#include<vector>
using namespace std;

template<typename E, typename C>
void partition(vector<E>& v, int low, int high, const C& less)
{
    if (low >= high)
    {
        return;
    }
    E pivot = v[low]; //select first as pivot
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (i <= j && less(v[i], pivot))
            i++;
        while (j >= i && !less(v[j], pivot))
            j--;
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    partition(v, low, j - 1, less);
    partition(v, j + 1, high, less);
}
template<typename E,typename C>
void quickSort(vector<E>& v, const C& less)
{
    if (v.size() <= 1) { 
        return;
    }
    partition(v, 0, v.size()-1, less);
}

int main()
{
    int n;
    cout << "Enter number of elements ";
    cin >> n;
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cout << v[i]<<" ";
    }
    quickSort(v, less<int>());
    cout << "\nAfter sort\n";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
}
/*
8
5 3 8 1 4 6 2 7
*/