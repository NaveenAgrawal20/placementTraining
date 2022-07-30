#include <iostream>
#define endl "\n"
using namespace std;

int solve(int *a, int n)
{
    int majIdx = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[majIdx] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            majIdx = i;
            count = 1;
        }
    }
    return a[majIdx];
}

int is_Majority(int majorityElem,int *a,int n)
{
    int count = 0;
    for(int i = 0;i<n;i++)
        if(a[i] == majorityElem)
            count++;

    if(count > n/2)
        return majorityElem;
    else
        return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int majority_elem =  solve(a, n);
        // checking if majority really exists
        cout<<is_Majority(majority_elem,a,n)<<endl;
    }
    return 0;
}
/*
3
5
1 3 2 2 2
5
1 2 3 2 2
4
1 3 2 2
*/