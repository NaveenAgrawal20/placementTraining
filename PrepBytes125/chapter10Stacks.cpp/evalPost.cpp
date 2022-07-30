#include<iostream>
#include<stack>
#include<string>
typedef long long ll;
using namespace std;

void evaluate(string &str) {
    int len = str.size();
    ll a, b;
    stack<ll> s;
    int i;
    for(i = 0;i<len;i++)
    {
        if(str[i] == ' ')
            continue;
        if(isdigit(str[i]))
        {
            int num = 0;
            while(isdigit(str[i]))
            {
                num = num * 10 + (int)(str[i] - '0');
                i++;
            }
            i--;
            s.push(num);
        }
        else{
            switch(str[i])
            {
                case '+':a = s.top();s.pop();
                        b = s.top();s.pop();
                        s.push(b+a);
                        break;
                case '-':a = s.top();s.pop();
                    b = s.top();s.pop();
                    s.push(b-a);
                    break;
                case '*':
                    a = s.top();s.pop();
                    b = s.top();s.pop();
                    s.push(b*a);
                    break;
                case '/':
                    a = s.top();s.pop();
                    b = s.top();s.pop();
                    s.push(b/a);
                    break;
            }
        }
    }
    cout<<s.top()<<"\n";
    s.pop();
}


int main() {
    int n;
    string str;
    cin >> n;
    cin.ignore();
    getline(cin,str);

    evaluate(str);
    return 0;
}
/*
3
2 3 +
3
45341 123312 *
 */