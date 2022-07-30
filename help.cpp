/*Check max value*/
#include <iostream>
#include <limits>

int main() {
    std::cout << std::numeric_limits<long long int>::max();
}
// view vector
*((int(*)[10])arrayName._M_impl._M_start)

//view an array
(int [10])*a

// #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

deepujind
deepu@584


https://www.geeksforgeeks.org/gcd-two-array-numbers/
https://www.geeksforgeeks.org/count-of-integers-that-divide-all-the-elements-of-the-given-array/


// 2d vector input from string

int main()
{
    int t = 5;
    while (t--)
    {
        string s;
        cin >> s;
        vector<vector<int>> grid;

        int i = 0;
        while (true)
        {
            vector<int> v;
            for (; i < s.size(); ++i) {
                if (s[i] == ']')
                {   
                    i++;
                    break;
                }
                else if (ispunct(s[i]) == 0)
                {
                    string str;
                    while(ispunct(s[i])==0)
                        str += s[i++];
                    i--;
                    v.push_back(stoi(str));
                }
            }
            if (i == s.size())
                break;
            grid.push_back(v);
        }
        cout<<"Str = "<<s<<'\n';
        for(auto e:grid)
        {
            for(auto v:e)
                cout<<v<<' ';
            cout<<'\n';
        }
        // Solution obj;
        // cout << obj.uniquePathsWithObstacles(grid) << endl;
    }

}