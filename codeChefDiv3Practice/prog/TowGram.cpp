#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, i, j, count, res = 0, u, v;
    string str;
    cin >> n;
    cin >> str;
    for (i = 0; i < n - 1; i++)
    {
        count = 0;
        for (j = i; j < n - 1; j++)
        {
            if (str[i] == str[j] && str[i + 1] == str[j + 1])
            {
                count++;
                if (count > res)
                {
                    res = count;
                    u = j;
                    v = j+1;
                }
            }
        }
    }
    cout << str[u] << str[v];
}