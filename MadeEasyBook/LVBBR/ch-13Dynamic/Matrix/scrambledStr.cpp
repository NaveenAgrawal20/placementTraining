#include <iostream>
using namespace std;

bool solve(string a, string b)
{
    if (a.length() != b.length())
        return false;
    int n = a.length();
    if (n == 0)
        return true;
    if (a == b)
        return true;

    for (int i = 1; i < n; i++)
    {
        // substr(starting_index,length)

        // swap = true
        // Check if S2[0...i] is a scrambled
        // string of S1[n-i...n] and S2[i+1...n]
        // is a scramble string of S1[0...n-i-1]
        if (solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i)))
            return true;

        // swap = false
        // Check if S2[0...i] is a scrambled
        // string of S1[0...i] and if S2[i+1...n]
        // is a scrambled string of S1[i+1...n]
        if (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i)))
            return true;
    }
    return false;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << (solve(a, b) ? 'T' : 'F') << '\n';
    return 0;
}

/*
coder
ocder
T
great
rgeat
T
abcde
caebd
F
*/