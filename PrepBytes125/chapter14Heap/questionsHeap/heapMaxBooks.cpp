#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, ele,count = 0,rp;
        cin >> n >> rp;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++)
        {
            cin >> ele;
            q.push(ele);
        }
        while (!q.empty() && rp != 0)
        {
            int t = q.top();
            q.pop();
            if (rp - t >= 0)
            {
                count++;
                rp = rp - t;
            }
            else
                break;
        }
        cout<<count<<"\n";
    }

    return 0;
}

// Sample Input
// 2
// 10 70
// 55 85 10 77 35 30 100 28 59 60
// 10 20
// 53 31 61 21 99 30 73 38 10 59

// Sample Output
// 3
// 1

// Sample test case explanation
// In test case one:
// Books with cost
// 10
// ,
// 28
// ,
// 30
//  can be purchased, therefore answer is
// 3
// .