#include <bits/stdc++.h>

using namespace std;
vector<string> getHtmlTags()
{                        // store tags in a vector
    vector<string> tags; // vector of html tags
    while (cin)
    { // read until end of file
        string line;
        getline(cin, line);           // input a full line of text
        int pos = 0;                  // current scan position
        int ts = line.find("<", pos); // possible tag start
        while (ts != string::npos)
        {                                                 // repeat until end of string
            int te = line.find(">", ts + 1);              // scan for tag end
            tags.push_back(line.substr(ts, te - ts + 1)); // append tag to the vector
            pos = te + 1;                                 // advance our position
            ts = line.find("<", pos);
        }
    }
    return tags; // return vector of tags
}

bool isHtmlMatched(const vector<string> &tags)
{
    stack<string> S;                               // stack for opening tags
    typedef vector<string>::const_iterator Iter; // iterator type
    // iterate through vector
    for (Iter p = tags.begin(); p != tags.end(); ++p)
    {
        if (p-> at(1) != '/') // opening tag?
            S.push(*p);       // push it on the stack
        else
        { // else must be closing tag
            if (S.empty())
                return false;                // nothing to match - failure
            string open = S.top().substr(1); // opening tag excluding ’<’
            string close = p-> substr(2);    // closing tag excluding ’</’
            if (open.compare(close) != 0)
                return false; // fail to match
            else
                S.pop(); // pop matched element
        }
    }
    if (S.empty())
        return true; // everything matched - good
    else
        return false; // some unmatched - bad
}

int main()
{
    cout << "Starting press ctrl+c to compile ";
    bool isTrue = isHtmlMatched(getHtmlTags());
    isTrue ? cout << "Html Compiled Successfull" : cout << "Failed to Compile";
    return 0;
}