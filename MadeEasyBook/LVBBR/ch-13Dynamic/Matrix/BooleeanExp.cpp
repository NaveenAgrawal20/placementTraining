#include <iostream>
using namespace std;

int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return s[i] == 'T'; // if T return 1
        else
            return s[i] == 'F'; // if F return 1 as (isTrue = False) else if T return 0
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int Lt = solve(s, i, k - 1, true);
        int Lf = solve(s, i, k - 1, false);
        int Rt = solve(s, k + 1, j, true);
        int Rf = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue)
                ans += Lt * Rt;
            else
                ans += Lt * Rf + Lf * Rt + Lf * Rf;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans += Lt * Rf + Lf * Rt + Lt * Rt;
            else
                ans += Lf * Rf;
        }
        else // XOR
        {
            if (isTrue)
                ans += Lt * Rf + Lf * Rt;
            else
                ans += Lf * Rf + Lt * Rt;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s, 0, s.length() - 1, true);
    return 0;
}