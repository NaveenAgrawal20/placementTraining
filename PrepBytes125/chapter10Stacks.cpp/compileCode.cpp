#include<iostream>
#include<stack>
#include<string>

#define endl "\n"
typedef long long ll;
using namespace std;

int longPrefix(string &str) {
    int len = str.size();
    int open = 0, close = 0, res = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (open == close && str[i] == '>') {
            return open + close;
        } else if (str[i] == '<') {
            open++;
        } else {
            close++;
            if (close == open)
                res = open + close;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, T;
    string str;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> str;
        cout << longPrefix(str) << endl;
    }
    return 0;
}
/*
14
<>
<<>>
><
<>>>
<><><
<><>>
<>><>
<<<<>
<>>>>
<<>>>
<<>><
<<><>
><><>
<<><>
-4
- 2
- 0
-2
-4
-4
-0
-0
-0
 */