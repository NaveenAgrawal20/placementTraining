#include<iostream>
#include<stack>
#include<string>

#define endl "\n"
typedef long long ll;
using namespace std;

int getTopTwo(stack<char> &s)
{
    char a,b;
    b = s.top();s.pop();
    a = s.top();s.pop();
    if(a == b)
        return 1;
    if(b == '{' && a == '}')
        return 2;
    return 0;
}

int main()
{
    int k = 1;
    while(true)
    {
        int count = 0;
        stack<char> s;
        string str;
        cin>>str;
        if(str[0] == '-')
            return 0;
        cout<<k++<<". ";

        // logic
        int len = str.length();
        for(int i = 0;i<len;i++)
        {
            if(s.empty() || str[i] == '{')
                s.push(str[i]);
            else{
                if(s.top() == '{')
                    s.pop();
                else
                    s.push('}');
            }
        }
        while(!s.empty())
            count += getTopTwo(s);

        cout<<count<<endl;
    }
}