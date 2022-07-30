#include<bits/stdc++.h>
using namespace std;

class Solution {
    string hash[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    public:
    void getCombination(string digits,int idx,string comb)
    {
        if(idx == digits.length())
        {
            ans.push_back(comb);
            return;
        }
        string alphasFordigit = hash[digits[idx] - '0'];
        for(int i = 0;i<hash[digits[idx] - '0'].length();++i)
        {
            comb += alphasFordigit[i];
            getCombination(digits,idx+1,comb);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        getCombination(digits,0,"");    
        return ans;
    }
};
/// Josephus circle
class Solution2 {
    class Node{
        public:
        int data;
        Node *next;
    };
public:
    int findTheWinner(int n, int k) {
        // Create a circular LL
        Node *p,*q;
        p = q= new Node();
        p->data = 1;
        for(int i = 2;i<=n;++i)
        {
            p->next = new Node();
            p = p->next;
            p->data = i;
        }
        // closing circular ll
        p->next = q;
        Node *t;
        t = p;
        // Eliminating members
        for(int count = 1;count <= n;++count)
        {
            for(int i = 0;i<k-1;++i)
                p = p->next;
            p->next = p->next->next;
        }
        return p->data;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    Solution s;
////    vector<string> ans =  s.letterCombinations("23");
////    for(auto e:ans)
////        cout<<e<<' ';
    Solution2 s;
    cout<<s.findTheWinner(5,2);
    return 0;
}