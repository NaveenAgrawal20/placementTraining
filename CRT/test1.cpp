#include<bits/stdc++.h>
using namespace std;

int main()
{
   string s = "scaler";
   int n = s.size();
   for(int i = 0; i < n; i++) {
       s = s + s[i];
   }
   cout << s << endl;
}