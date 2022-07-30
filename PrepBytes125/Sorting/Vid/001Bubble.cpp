#include <iostream>
#define endl "\n"
using namespace std;
void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void decbubbleSort(int *a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int swapped = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped++;
            }
        }
        if (!swapped)
            cout << "Already Sorted";
        break;
    }
}

void selectionSort(int *a, int n)
{
    int m;
    for (int i = 0; i < n - 1; i++)
    {
        m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[m] > a[j])
                m = j;
        }
        if (m != i)
            swap(a[i], a[m]);
    }
}
void insertionSort(int *a, int n)
{
    int j, k, i;
    for (i = 1; i < n; i++)
    {
        k = a[i];
        for (j = i-1; j >= 0 && a[j] > k; j--)
            a[j+1] = a[j];
        a[j+1] = k;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // decbubbleSort(a, n);
        // selectionSort(a, n);
        insertionSort(a, n);
        display(a, n);
    }
    return 0;
}