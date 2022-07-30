#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        map<int,int> s;
        bool f = false;
        int a;
        for(int i = 1;i<=4;i++)
        {    
            cin>>a;
            s[a]++;
            if(s[a] >= 3)
                f = true;
        }if (s.size() == 4)
            cout<<2;
        else if(s.size() == 3)
            cout<<2;
        else if(s.size() == 2)
            if(f)
                cout<<1;
            else
                cout<<2;
        else
            cout<<0;
        cout<<"\n";
    }
    return 0;
}
// 6
// 1 4 3 2
// 4 5 5 5
// 4 5 3 5
// 4 4 4 5
// 5 5 2 1
// 4 3 4 3
