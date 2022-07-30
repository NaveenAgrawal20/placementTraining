#include <iostream>
#include <string>
using namespace std;

// array rotation : Reversal algo
// here d = 2

void strReverse(string &a, int start, int end)
{
    char temp;
    while (start < end)
    {
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
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
        int n, i, opCount = 0;
        char temp;
        string str, passw;
        cin >> passw;
        cin >> str;
        n = passw.length();
        if (n != str.length())
        {
            cout << "No\n";
            break;
        }
        if (passw[n - 1] == str[1] && passw[n - 2] == str[0])
        {
            strReverse(str, 0, d - 1);
            strReverse(str, d, n - 1);
            strReverse(str, 0, n - 1);
        }
        else if(passw[0] == str[n - 2] && passw[1] == str[n-1])
        {
            // right
            strReverse(str, 0,n- d - 1);
            strReverse(str, n-d, n - 1);
            strReverse(str, 0, n - 1);
        }

        if (str == passw)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
/*
6
string
ngstri
string
ringst
study
ystud
balistic
icbalist
idiom
onidi
archelogist
starchelog


Read the question carefully, it is only written rotate by 
2
 places and no other restrictions
 https://www.geeksforgeeks.org/check-string-can-obtained-rotating-another-string-2-places/
If you are using character array, make sure to give extra space for null character.
Use debugging statements, print the string to check if the input is correctly taken or not.
Test your code for multiple test cases at once.
*/