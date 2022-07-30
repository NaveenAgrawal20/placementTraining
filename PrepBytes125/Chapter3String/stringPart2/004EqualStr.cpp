#include <iostream>
#include <climits>
#include <string>
using namespace std;

int minOperation(string words[], int n)
{
    int count = 0,i,j,ans = INT_MAX;
    string temp;
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            temp = words[j] + words[j];
            int idx = temp.find(words[i]);

            if (idx == string::npos)
                return -1;

            count += idx;
        }
        ans = min(ans,count);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int d = 2;
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        string words[n];
        for (int i = 0; i < n; i++)
            cin >> words[i];
        cout<<minOperation(words, n)<<"\n";
    }
    return 0;
}
/*
2
2
abcde
cdeab
5
abcde
cdeab
deabc
bcdea
eabcd
*/