// #include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout<<('a' > 'b')<<endl; false
    // cout<<('a' > 'b')<<endl; true
    int T;
    cin >> T;
    while (T--)
    {
        int i,j;
        string str;
        cin>>str;
        int n = str.size();
        for(i = 0;i<n-1;i++)
        {
            for(j = 0;j<n - i-1;j++)
            {
                if(str[j] < str[j+1])
                {
                    char temp = str[j];
                    str[j] = str[j+1];
                    str[j+1] = temp;
                }
            }
        }
        cout<<str<<endl;
    }

    return 0;
}
/*
2
prepbytes
algorithm
*/