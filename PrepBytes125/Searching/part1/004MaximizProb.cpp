#include <iostream>
#define endl "\n"
#define MAX 11
using namespace std;

int a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 1;i<=MAX;i++)
        a[i] = 5 * i;

    int T;
    cin >> T;
    while (T--)
    {
        int n,k,i;
        cin >> n >> k;
        k = 240 - k; //18
        int sum = 0;
        for(i = 1;i<=n;i++)
        {
            sum += a[i];
            if(sum > k)
                break;
        }
        cout<<i-1<<endl;
    }
    return 0;
}