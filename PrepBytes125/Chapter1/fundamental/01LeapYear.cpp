#include <iostream>
using namespace std;

int main()
{
    int year,n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin >> year;
        if (year % 100 == 0)
        {
            if (year / 100 % 4 == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
        {
            if (year % 4 == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}