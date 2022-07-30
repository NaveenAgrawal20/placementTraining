// #include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int i,prevIdx = 1;
        string str;
        cin>>str;
        int n = str.size(),count = 0;
        for(i = 0;i<n-3;i++)
        {
            if(str[i] == 'a' && str[i+1] == 'm' && str[i+2] == 'a' && str[i+3] == 'n')
            {
                count += abs(i - prevIdx) * (n - i - 3);
                prevIdx = i;
            }
        }
        cout<<count<<"\n";
    }

    return 0;
}
/*
1
amanaaamanc
*/