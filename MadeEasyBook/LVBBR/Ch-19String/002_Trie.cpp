#include<bits/stdc++.h>
#define ALPH_S 26
using namespace std;

struct TrieNode
{
    TrieNode *children[ALPH_S];
    bool endOfWord;
};

TrieNode* getNode()
{
    TrieNode *node = new TrieNode();
    for(int i = 0;i<ALPH_S;++i)
        node->children[i] = NULL;
    node->endOfWord = false;
    return node;
}

void insert(TrieNode* root, string s)
{
    TrieNode* crawl = root;
    for(int i = 0;i<s.length();++i)
    {
        int idx = s[i] - 'a';
        // not yet inserted
        if(!crawl->children[idx])
        {
            crawl->children[idx] = getNode();
        }
        crawl = crawl->children[idx];
    }
    crawl->endOfWord = true;
}

bool search(TrieNode* root,string key)
{
    TrieNode* crawl = root;
    for(int i = 0;i<key.length();++i)
    {
        int idx = key[i] - 'a';
        // idx not exist
        if(!crawl->children[idx])
        {
            return false;
        }
        crawl = crawl->children[idx];
    }
    return crawl->endOfWord;
}

int main()
{
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
  
    TrieNode *root = getNode();
  
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
  
    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
                           cout << "No\n";
    search(root, "their")? cout << "Yes\n" :
                         cout << "No\n";
    search(root, "thaw")? cout << "Yes\n" :
                           cout << "No\n";
    return 0;
    return 0;
}