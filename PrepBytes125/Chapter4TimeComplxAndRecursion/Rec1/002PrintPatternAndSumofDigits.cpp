#include<iostream>
#include<string>
#define endl "\n";

using namespace std;

void solve(int n)
{
    if(n <= 0)
    {
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    solve(n-5);
    cout<<n<<" ";
}

int sumFunc(int n,int i = 0)
{
    if(n == 0)
        return i;
    return sumFunc(n/10,i+n%10);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin>>T;
    while(T--)
    {
        int n,i;
        cin>>n;
        // solve(n);
        cout<<sumFunc(n)<<endl;
    }
    return 0;
}