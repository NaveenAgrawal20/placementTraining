#include <bits/stdc++.h>
using namespace std;

void printAllSub(string s, int i, string &str)
{
    if (i == s.length())
    {
        cout << str << " ";
        return;
    }
    // pick
    str += s[i];
    printAllSub(s,i+1,str);
    
    // not pick
    // but first also remove the char from str (as it is not pick)
    str.pop_back();
    printAllSub(s,i+1,str);
}

int main()
{
    string s, str="";
    cin >> s;
    printAllSub(s, 0, str);
    return 0;
}
/*
abc
a b c ab ac bc abc
*/