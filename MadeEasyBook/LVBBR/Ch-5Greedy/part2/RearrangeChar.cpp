#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class Node
{
public:
    char data;
    int freq;
    Node(){};
    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
    }
    // function for priority_queue to store Key
    // according to freq
    bool operator<(const Node &node) const
    {
        return this->freq < node.freq;
    }
};

void rearrangeString(string str)
{
    int n = str.size();
    // Store frequencies of all characters in string
    int countChar[26] = {0};
    for (int i = 0; i < n; i++)
        countChar[str[i] - 'a']++;
    // max heap
    priority_queue<Node> pq;
    for(int i = 0;i<26;i++)
    {
        if(countChar[i])
        {
            pq.push(Node('a'+i,countChar[i]));
        }
    }

    // main algo
    string res = "";
    // temp Node var to store previous extracted Node
    Node prev;

    prev = Node('#', 0); // initial value for prev
    while (!pq.empty())
    {
        Node ext = pq.top();
        pq.pop();
        ext.freq--;
        res += ext.data;

        if (prev.freq > 0)
            pq.push(prev);
        prev = ext;
    }
    if (res.size() == n)
        cout << res << '\n';
    else
        cout << "Not Possible\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin>>str;
        rearrangeString(str);
    }
    return 0;
}
/*
*(char(*)[10])res // DEBUG STRING
8
aaabc
aaabb
bbbaa
gfggh
tkk
aa
a
ab
*/