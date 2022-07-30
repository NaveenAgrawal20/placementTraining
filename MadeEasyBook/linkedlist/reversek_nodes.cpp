#include <iostream>
#include <stack>
#include <vector>
#include "SllinkedList.h"

void display(SllNode *head)
{
    SllNode *crawl = head;
    while(crawl)
    {
        cout<<crawl->data<<' ';
        crawl = crawl->next;
    }
    cout<<'\n';
}
// Reverse K node
SllNode *reverseKNodes(SllNode *head, int k) {
    if(k == 0 || k == 1)
        return head;
    SllNode *curr = head,*prev = NULL, *next = NULL;
    int count = 0;
    // simple reverse for k nodes
    while(count < k && curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    //still nodes present
    if(next)
        head->next = reverseKNodes(curr,k);
    return prev;
}

string removeDuplicatesS(string S, int K) {
    int i, j;
    stack<int> st;
    st.push(0);
    for (i = 1, j = 1; j < S.size(); i++, j++) {
        S[i] = S[j];
        if (i == 0 || S[i] != S[i-1]) st.push(i);
        else if (i - st.top() + 1 == K) {
            i = st.top() - 1;
            st.pop();
        }
    }
    return S.substr(0, i);
}
string removeDuplicates(string s, int k) {
    vector<pair<char,int>> stk; // stack for char and its frequency

    for(char c:s)
    {
        if(stk.empty() || (stk.back().first != c))
            stk.emplace_back(c,1);
        else
        {
            stk.back().second += 1; // if same as top inc freq
            if(stk.back().second == k) // remove char from stack if it occurs k times
                stk.pop_back();
        }
    }

    string ans = "";
    for(pair<char,int> ele:stk)
    {
        ans.append(ele.second,ele.first);
        /*append ele.second (freq=num) occurences of ele.first(char) */
    }
    return ans;
}

int main() {
    cout<<removeDuplicates("deeedbbcccbdaa",3)<<'\n';
    cout<<removeDuplicates("pbbcggttciiippooaais",2)<<'\n';
    cout<<removeDuplicates("abcd",2)<<'\n';
//    Sll *ll1 = new Sll();
//    int n;
//    cout << "enter numbers to insert into list, -1 to stop : ";
//
//    while (1) {
//        cin >> n;
//        if (n == -1)
//            break;
//        ll1->insert_node_AtEnd(n);
//    }
//    display(ll1->head);
//    int k;
//    cin >> k;
//    ll1->head = reverseKNodes(ll1->head, k);
//    display(ll1->head);

}
/*
1
2
3
4
5
6
7
8
9
10
-1
4
*/