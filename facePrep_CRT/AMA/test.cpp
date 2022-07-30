#include<bits/stdc++.h>
using namespace std;
int dat(string str)
{
    string str2;
    unordered_set <string> dates;
    for(int i = 0;i<str.length();++i)
    {
        if(isdigit(str[i]))
            str2 += str[i];
        else if(str[i] == '-')
            str2.clear();
        else if(str.length() == 4)
        {
            dates.insert(str2);
            str2.clear();
        }
        else
            str2.clear();
    }
    return dates.size();
}
int main()
{
    string str;
    getline(cin,str);
    cout<<dat(str)<<endl;
    return 0;
}