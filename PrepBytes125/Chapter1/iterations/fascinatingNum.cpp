#include <iostream>
using namespace std;

int countDistinct(int n)
{
    int arr[10] = {0};
    int count = 0;
    while (n)
    {
        arr[n % 10] = 1;
        n /= 10;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (arr[i])
            count++;
    }
    return count;
}

int getNextDig(int n)
{
    while (n < 10000)
    {
        int d = countDistinct(n);
        if (d == 4)
            return n;
        n++;
    }
    return n;
}

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << getNextDig(n+1) << "\n";
    }
    return 0;
}