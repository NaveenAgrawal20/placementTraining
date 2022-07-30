/*
 * Created By Naveen
 * Created on 2021
 * Copyright © 2021
 Description ==> // Matching Tags in an HTML Document
 Reference = basix/String basix /substrProg.cpp
 */

#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;
/*
This procedure getHtmlTags reads the input line by line, extracts all the
tags as strings, and stores them in a vector, which it returns. we store '<TAG>'
 */
vector<string> getHtmlTag()
{
    vector<string> htmlTags;
    while(cin)
    {
        string line;
        getline(cin,line);
        int pos = 0;
        int tagStart = line.find('<',pos);
        while(tagStart != string::npos)
        {
            int tagEnd = line.find('>',tagStart+1);
            htmlTags.push_back(line.substr(tagStart,tagEnd-tagStart+1));
            pos = tagEnd+1;
            tagStart = line.find('<',pos);
        }
    }
    return htmlTags;
}

bool isHtmlMatched(const vector<string> &tags)
{
    stack<string> sTopen; // stack for opening tags
    typedef vector<string>::const_iterator iter;
    for(iter p = tags.begin();p!=tags.end();p++)
    {
        if(p->at(1) != '/' ) // opening tag (if true)
            sTopen.push(*p);
        else
        {
            if(sTopen.empty()) return false; // nothing to match - failure
            string openTag = sTopen.top().substr(1);  // excluding '<'
            sTopen.pop();   
            string closeTag = p->substr(2); // excluding '</'
            if(openTag.compare(closeTag) != 0)
                return false;
        }
    }
    if(sTopen.empty()) return true; // everything matched
    else return false;
}

int main()
{
    cout<<"Starting Press ENTER and then ctrl+c to Compile ";
    bool isTrue = isHtmlMatched(getHtmlTag());
    isTrue?cout<<"Html Compiled Successfull":cout<<"Failed to Compile";
    return 0;
}
/*
<body>
<center>
<h1> The Little Boat </h1>
</center>
<p> The storm tossed the little
boat like a cheap sneaker in an
old washing machine. The three
drunken fishermen were used to
such treatment, of course, but
not the tree salesman, who even
as a stowaway now felt that he
had overpaid for the voyage. </p>
<ol>
<li> Will the salesman die? </li>
<li> What color is the boat? </li>
<li> And what about Naomi? </li>
</ol>
</body>
*/