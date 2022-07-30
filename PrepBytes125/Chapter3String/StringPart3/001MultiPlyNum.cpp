#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void multi(string s, string t, int sn, int tn)
{
    int i, termAns = 0, j, carry = 0, ans = 0, a = 0, b = 0, finalAns = 0;

    b = 0;
    for (i = tn - 1; i >= 0; i--) 
    {
        a = 0;
        ans = 0;
        for (j = sn - 1; j >= 0; j--)
        {
            int u = (s[j] - '0');
            int v = (t[i] - '0');
            termAns = u * v + carry;
            carry = termAns / 10;
            termAns = termAns % 10;
            ans = termAns * pow(10, a) + ans;
            a++;
        }
        finalAns += ans * pow(10, b);
        b++;
    }
    cout << finalAns << "\n";
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
        int sn = s.length();
        int tn = t.length();
        if(sn < tn)
            s = string(tn - sn,'0').append(s);
        else
            t = string(sn - tn,'0').append(t);
        
        sn = s.length();
        tn = t.length();
        multi(s,t,sn,tn);
    }
    return 0;
}
/*
3
15 15
2 4
10 4
*/

/*
You can not store such large numbers in any data type.
So you need to multiply the strings and store them in string only.
Think of using this formula , 32*54 = {32*4 + 32*50} and 123*456 = {123*6 + 123*50 + 123*400}.
Take care of carry each time.
Take some test cases to verify your code.
It can also be solved using Divide and Conquer.
*/