#include <iostream>
#include <string>
using namespace std;

void strReverse(string &a, int start, int end)
{
    char temp;
    while (start < end)
    {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, l, r, k, i;
    string str;
    cin >> str;
    cin >> m;
    int len = str.length();
    for (i = 1; i <= m; i++)
    {
        cin >> l >> r >> k;
        l = l - 1;
        r = r - 1;

        if (k>(r-l+1))
            k=k%(r-l+1);

        strReverse(str, l, r - k);
        strReverse(str, r - k + 1, r);
        strReverse(str, l, r);
    }
    cout << str << "\n";

    return 0;
}
/*
bcbdbcb
2
3 6 1
1 4 2

*/