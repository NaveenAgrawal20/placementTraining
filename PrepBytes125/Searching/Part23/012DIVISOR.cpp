#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
}