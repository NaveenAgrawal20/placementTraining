#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string s = "This is fine";
    cout<<s.substr(8,2)<<endl; // here 8 is char index and 2 is num of char in subString. //fi
    s = "<This> is fine";
    int ts = s.find('<',0);
    int te = s.find('>',ts);
    cout<<ts<<" <--> "<<te<<" =  "<<s.substr(ts,te-ts+1); //0 <--> 5 =  <This>
    cout<<endl;
    vector<string> v{"Jack","Dog"};
    vector<string>::const_iterator iter = v.begin();
    for(;iter != v.end();iter++){
        cout<<*iter<<" "; // or cout<<iter->data()<<" "; //output => Jack,Dog
        // cout<<iter->at(1)<<" "; // output =>a o
    }
    return 0;

}