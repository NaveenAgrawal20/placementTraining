#include<iostream>
#include<stack>
#include<string>

#define endl "\n"
#define C 12
#define O 16
#define H 1
typedef long long ll;
using namespace std;

int getV(char c) {
    switch (c) {
        case 'C':
            return C;
        case 'O':
            return O;
        case 'H':
            return H;
        default:
            return 0;
    }
}

int getM(string &str) {
    bool isNum;
    stack<char> s;
    stack<int> mass;
    mass.push(0);
    char ch;
    int m = 1, tmass, m2 = 1;
    int len = str.size();
    for (int i = 0; i < len; i++) {
        if (str[i] != ')') {
            s.push(str[i]);
            if (str[i] == '(')
                mass.push(0);
        } else {
            if (i + 1 < len && isdigit(str[i + 1]))
                m = str[++i] - '0';
            else
                m = 1;
            do {
                isNum = false;
                ch = s.top();
                s.pop();
                switch (ch) {
                    case '(':
                        tmass = mass.top();
                        mass.pop();
                        tmass = tmass * m + mass.top();
                        break;
                    case 'C':
                        tmass = mass.top();
                        tmass += getV(ch) * m2;
                        break;
                    case 'O':
                        tmass = mass.top();
                        tmass += getV(ch) * m2;
                        break;
                    case 'H':
                        tmass = mass.top();
                        tmass += getV(ch) * m2;
                        break;
                    default:
                        isNum = true;
                        m2 = ch - '0';
                }
                if(!isNum)
                {
                    m2 = 1;
                    mass.pop();
                    mass.push(tmass);
                }
            } while (ch != '(');
        }
    }
    while(!s.empty())
    {
        isNum = false;
        ch = s.top();
        s.pop();
        switch (ch) {
            case 'C':
                tmass = mass.top();
                tmass += getV(ch) * m2;
                break;
            case 'O':
                tmass = mass.top();
                tmass += getV(ch) * m2;
                break;
            case 'H':
                tmass = mass.top();
                tmass += getV(ch) * m2;
                break;
            default:
                isNum = true;
                m2 = ch - '0';
        }
        if(!isNum)
        {
            m2 = 1;
            mass.pop();
            mass.push(tmass);
        }
    }

    return mass.top();
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        str = str;
        cout << getM(str) << endl;
    }
    return 0;
}