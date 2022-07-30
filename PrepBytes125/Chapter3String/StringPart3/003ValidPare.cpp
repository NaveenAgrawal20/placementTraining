#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int i, n;
        bool valid = true;
        vector<char> brackets;
        string s;
        cin >> s;
        s = "(" + s + ")";
        n = s.length();
        if (n % 2 == 1)
            valid = false;
        else
        {
            for (i = 0; i < n; i++)
            {
                if (s[i] == '(')
                {
                    brackets.push_back('(');
                }
                else
                {
                    //if size != 0 that means we have open brackets present
                    // and we can match them against ")"
                    if (brackets.size() != 0)
                        brackets.pop_back();
                    else
                        valid = false;
                }
            }
            if(brackets.size() != 0)
                valid = false;
        }
        if(valid)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
/*
7
()
)(
(())
))((
()())(
()(
))()(())
*/