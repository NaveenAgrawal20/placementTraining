#include <iostream>
#define endl "\n"
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int partition(int *a, int low, int high)
{
    int pivot = low;
    int i = low + 1, j = high;
    while (i <= j)
    {
        while (a[i] < a[pivot] && i < high)
            i++;
        while (a[j] > a[pivot])
            j--;
        if (i < j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        else
            i++;
    }
    swap(a[j], a[pivot]);
    return j;
}

void quickSort(int *a, int low, int high)
{
    if (low >= high)
        return;
    int pivot = partition(a, low, high);
    quickSort(a, low, pivot - 1);
    quickSort(a, pivot + 1, high);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("outputQ.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        quickSort(a, 0, n - 1);
        display(a, n);
    }
    return 0;
}