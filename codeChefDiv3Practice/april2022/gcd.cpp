#include <bits/stdc++.h>
using namespace std;

void minSumGcd(int a, int b)
{
    if(a % 2== 0)
    {
        if(b-a >= 2)
            cout<<a<< ' '<<a+2<<'\n';
        else
            cout<<"-1\n";
    }
    else{
        if(b - a >= 3)
        {
            if(a % 3 == 0)
                cout<<a<<' '<<a+3<<'\n';
            else
                cout<<a+1<<' '<<a+3<<'\n';
        }
        else
        {
            cout<<-1<<'\n';
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        minSumGcd(a, b);
    }
    return 0;
}
/*
6
2 3
2 4
10 12
10 15
10 20
13 39
*/