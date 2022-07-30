#include <iostream>
#include <queue>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string s1,s2;
        queue<string> q;
        q.push("1");
        for(int i = 1;i<=n;i++){
            s1 = q.front();q.pop();
            cout<<s1<<"\n";
            s2 = s1;
            s1 += '0';
            q.push(s1);
            s2 += '1';
            q.push(s2);
        }
    }

    return 0;
}
