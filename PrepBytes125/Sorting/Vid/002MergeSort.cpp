#include <iostream>
#define endl "\n"
using namespace std;

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void merge(int *a, int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid, i, j, k;
    int *leftArr = new int[n1], *rightArr = new int[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = a[left+i];

    for (i = 0; i < n2; i++)
        rightArr[i] = a[mid+1+i];

    k = left;
    for (i = 0, j = 0; i < n1 && j < n2;)
    {
        if (leftArr[i] < rightArr[j])
            a[k++] = leftArr[i++];
        else
            a[k++] = rightArr[j++];
    }
    while (i < n1)
        a[k++] = leftArr[i++];
    while (j < n2)
        a[k++] = rightArr[j++];
}

void mergeSort(int *a, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge(a, left, mid, right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("outputM.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        mergeSort(a,0,n-1);
        display(a, n);
    }
    return 0;
}
