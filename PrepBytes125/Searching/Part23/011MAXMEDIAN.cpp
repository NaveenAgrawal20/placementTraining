#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;
typedef long long ll;

bool checkMedian(int *a, ll midMed, int n, int k)
{
    ll oper = 0;
    for (int i = n / 2; i < n; i++)
    {
        if (midMed - a[i] > 0)
        {
            oper += midMed - a[i]; // oper required to make right array equal to midMed
            if (oper > k)
                return false;
        }
    }
    return oper <= k;
}

int solve(int *a, int n, int k)
{
    ll ans;
    // median can range between 1 to max value of array + k
    int maxValArr = 0;
    for (int i = 0; i < n; i++)
        maxValArr = max(maxValArr, a[i]);

    ll smallestMed = 1, highestMed = maxValArr + k;
    while (smallestMed <= highestMed)
    {
        ll midMedian = smallestMed + (highestMed - smallestMed) / 2;

        if (checkMedian(a, midMedian, n, k))
        {
            smallestMed = midMedian + 1;
            ans = midMedian;
        }
        else
            highestMed = midMedian - 1;
    }
    return ans;
}
int main()
{
    int n, k;

    cin >> n >> k;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    cout << solve(a, n, k) << endl;
}
