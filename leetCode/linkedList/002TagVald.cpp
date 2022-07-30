#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

// save "<TAG>" and "</TAG>"
vector<string> extractTags(string str)
{
	vector<string> vec;
	int pos = 0,i = 0;
	int tagEnd,tagStart = str.find('<', pos),ctag;
	string subStr;
	while (tagStart != string::npos)
	{
		tagEnd = str.find('>', tagStart + 1);
		
		subStr = str.substr(tagStart, tagEnd - tagStart + 1);
		string ch = subStr.substr(0, 8);
		if (subStr.substr(0, 8) == "<![CDATA")
		{
			pos = str.find("]]>", subStr.length());
			tagStart = str.find('<', pos);
			continue;
		}
		vec.push_back(subStr);
		pos = tagEnd + 1;
		tagStart = str.find('<', pos);
	}
	return vec;
}
bool tagChecker(vector<string>& vec)
{
	stack<string> s1;
	string tag;
	if(vec.size() == 0)
		return false;
	vector<string>::iterator p = vec.begin();
	for (; p != vec.end(); p++)
	{
		tag = *p;
		transform(tag.begin(), tag.end(),tag.begin(),toupper);
		if (*p != tag || tag.length() > 9 )
			return false;
		if (p->at(1) != '/') // openning Tag
			s1.push(*p);
		else
		{
			if (s1.empty())
				return false;
			else
			{
				if (s1.top().substr(1) != p->substr(2))
					return false;
				s1.pop();
			}
		}
	}
	return s1.empty() ? true : false;
}
int main()
{
	string str;
	vector<string> vec;
	getline(cin, str);
	vec = extractTags(str);
	if (tagChecker(vec)) 
		cout<<"true";
	else
		cout << "false";
	return 0;
}
/*
<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>
<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>
*/