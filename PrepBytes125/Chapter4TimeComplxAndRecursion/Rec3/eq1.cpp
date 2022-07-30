#include <iostream>
using namespace std;

int countSolutions(int n, int val)
{
    int total = 0;

    if (n == 1 && val >= 0)
        return 1;

    for (int i = 0; i <= val; i++)
    {

        total += countSolutions(n - 1, val - i);
    }

    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n, z;
        cin >> n >> z;
        cout << countSolutions(n, z)<<"\n";
    }
}