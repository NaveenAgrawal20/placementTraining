#include<bits/stdc++.h>

using namespace std;

string nextGreater(string str)
{
    int i;
    int n = str.length();
    for(i = n-1;i>0;--i)
        if(str[i] > str[i-1])
            break; // if valid break

    if(i == 0)
        return "-1";
    
    for(int j = n-1;j>=i;j--)
    {
        if(str[i-1] < str[j])
        {
            swap(str[i-1],str[j]);
            break;
        }
    }
    reverse(str.begin()+i,str.end());
    return str;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout<<nextGreater(str)<<endl;
    }
    return 0;
}