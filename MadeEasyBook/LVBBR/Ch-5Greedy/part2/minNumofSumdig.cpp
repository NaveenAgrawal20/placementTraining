#include <iostream>
#include<string>
using namespace std;

string minSumDig(int s, int d)
{
    string res;
    for(int i = 0;i<d;i++)
        res += '0';
    res[0] = '1';
    if (s > 9 * d) // sum greater than max value of digits //eg 9+9+9 = 27 for 3 dig
    {
        return "-1";
    }
    s = s - 1;
    int i;
    for (i = d - 1; i >= 1 && s >= 0; i--)
    {
        if (s > 9)
            res[i] = '9';
        else
            res[i] = s+'0';
        s = s - 9;
    }
    if (s >= 0)
        res[0] = (1+s)+'0';
    return res;
}

int main()
{
    int s, d,t;
    cin >> t;
    while (t--)
    {
        cin >> s >> d;
        cout<<minSumDig(s, d)<<'\n';
    }
    return 0;
}
/*
7
6 6
42 6
9 2
18 2
20 3
2 1
50 2

*/