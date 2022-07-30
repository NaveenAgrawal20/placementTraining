#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class BinaryTreeNode{
    public:
    unsigned freq;
    char data;
    BinaryTreeNode *left,*right;
    BinaryTreeNode(){};
    BinaryTreeNode(char data, unsigned freq,BinaryTreeNode *left = NULL,BinaryTreeNode *right = NULL){
        this->data = data;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};
struct Compare{
    bool operator()(BinaryTreeNode *l,BinaryTreeNode *r){
        return l->freq > r->freq;
    }
};
void encode(BinaryTreeNode* root,string str,unordered_map<char,string> &huffmanCodes)
{
    if(!root)
        return;
    if(root->data != '$')
        huffmanCodes[root->data] = str;
    encode(root->left,str+"0",huffmanCodes);
    encode(root->right,str+"1",huffmanCodes);
}
void HuffmanCodes(char *data,int *freq, int n)
{

    priority_queue<BinaryTreeNode*,vector<BinaryTreeNode*>,Compare> pq;
    for(int i = 0;i<n;i++)
        pq.push(new BinaryTreeNode(data[i],freq[i]));
    
    BinaryTreeNode *left,*right;
    while(pq.size() != 1)
    {
        left = pq.top();pq.pop();
        right = pq.top();pq.pop();
        
        unsigned sum = left->freq + right->freq;
        pq.push(new BinaryTreeNode('$',sum,left,right));
    }

    // Getting Codes of Huffman in a map
    unordered_map<char,string> huffmanCodes;
    encode(pq.top(),"",huffmanCodes);

    // printing codes for huffman tree
    for(pair<char,string> code:huffmanCodes)
        cout<<code.first<<" : "<<code.second<<'\n';
    /*
    https://www.techiedelight.com/huffman-coding/
    */

} 

int main()
{
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
  
    int size = sizeof(arr) / sizeof(arr[0]);
  
    HuffmanCodes(arr, freq, size);
    return 0;
}