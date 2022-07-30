#include <iostream>
#include <string>
using namespace std;

string multiPly(string num1, string num2)
{
    int sn, tn, i, j, n1, n2, multi, carry = 0, idx = 0;
    // s * t = n1 * n2;
    sn = num1.length();
    tn = num2.length();
    int result[sn + tn] = { 0 };
    // innerIdx for moving (for eg. as in s[0,n-1] * t[0]);
    // outerIdx for moving terms;
    int outerIdx = 0, innerIdx = 0;

    for (i = tn - 1; i >= 0; i--)
    {
        n2 = num2[i] - '0';
        carry = 0;
        innerIdx = 0;
        for (j = sn - 1; j >= 0; j--)
        {
            n1 = num1[j] - '0';
            multi = n1 * n2 + result[outerIdx + innerIdx] + carry;
            carry = multi / 10;
            result[outerIdx + innerIdx] = multi % 10;
            innerIdx++;
        }
        result[outerIdx + innerIdx] += carry;
        outerIdx++;
    }
    // saving int arr to string with ignoring 0 from right
    i = sn + tn - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    // result 0
    if(i == -1)
        return "0";

    string ans = "";
    for (; i >= 0; i--)
        ans += to_string(result[i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        string s, t, temp;
        cin >> s;
        cin >> t;
        cout << multiPly(s, t) << "\n";
    }
    return 0;
}
/*
10
2 3
5 15
15 15
13 13
3 68
990123912412323112 213912031231238
0 213213
100 1000
512 132041321321
2130 213213213
*/