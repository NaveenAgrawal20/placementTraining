
/*
Efficient Solution : The key idea is to perform binary search over the answer K, since if some character c appears in all substrings of length X, it will always appear in all substrings of length (X + 1). Hence, we can check for the current length and try to minimise it using divide and conquer algorithm. 
For checking if some character appears in all substrings of length X, iterate over all characters from ‘a’ to ‘z’ and inside another loop iteratively store the last occurrence of the last character. 
Let the current position be j, so the last substring of length X will be from (j – X) to X. Check if the position of last occurrence of current K-amazing character is greater than (j – X) or not. If it is greater, then that substring is a valid string.
Below is the implementation of the above approach. 
*/



// CPP Program to find minimum K such that
// every substring of length atleast K
// contains some character c
#include <bits/stdc++.h>
using namespace std;
 
// This function checks if there exists some
// character which appears in all K length
// substrings
int check(string s, int K)
{
    // Iterate over all possible characters
    for (int ch = 0; ch < 26; ch++) {
        char c = 'a' + ch;
 
        // stores the last occurrence
        int last = -1;
 
        // set answer as true;
        bool found = true;
        for (int i = 0; i < K; i++)
            if (s[i] == c)
                last = i;
 
        // No occurrence found of current
        // character in first substring
        // of length K
        if (last == -1)
            continue;
 
        // Check for every last substring
        // of length K where last occurrence exists in substring
        for (int i = K; i < s.size(); i++) {
            if (s[i] == c)
                last = i;
 
            // If last occ is not
            // present in substring
            if (last <= (i - K)) {
                found = false;
                break;
            }
        }
        // current character is K amazing
        if (found)
            return 1;
    }
    return 0;
}
 
// This function performs binary search over the
// answer to minimise it
int binarySearch(string s)
{
    int low = 1, high = (int)s.size();
    int ans;
    while (low <= high) {
        int mid = (high + low) >> 1;
 
        // Check if answer is found try
        // to minimise it
        if (check(s, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
 
// Driver Code to test above functions
int32_t main()
{
    string s = "abcde";
    cout << binarySearch(s) << endl;
 
    s = "mnopq";
    cout << binarySearch(s) << endl;
    return 0;
}
