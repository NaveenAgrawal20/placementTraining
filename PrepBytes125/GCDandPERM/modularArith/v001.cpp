#include <iostream>
#include <string>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        long long int oneC = 0;
        for(int i = 0;i<n;i++)
        {
            if(str[i] == '1')
                oneC++;
        }
        cout<<oneC*(oneC+1)/2<<endl;
    }
    return 0;
}
/*
q2
https://www.geeksforgeeks.org/
repeated-subtraction-among-two-numbers/
*/