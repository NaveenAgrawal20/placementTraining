#include <iostream>
#include <algorithm>
using namespace std;

void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void solve(int *arr, int start, int siz) {
    if (start == siz - 1) {
        print(arr, siz);
        swap(arr[0], arr[start]);
        return;
    }
    for (int i = start; i < siz; i++) {
        swap(arr[i], arr[start]);
//        sort(arr+start+1,arr+siz);
        solve(arr, start + 1, siz);
        swap(arr[i], arr[start]);
    }
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    solve(arr, 0, n);

    return 0;
}