#include <iostream>
#define endl "\n";
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        // int *a = new int[n];
        int count = 0;
        int max = 0, h;
        for (int i = 0; i < n; i++)
        {
            cin >> h;
            if (h > max)
            {
                max = h;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
/*
2
5
7 4 8 2 9
4
2 3 4 5
*/