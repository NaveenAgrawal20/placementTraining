#include <iostream>
#include "BinaryTree.h"
#include <queue>
#include <unordered_map>
#include <math.h>
#include <iomanip> // setprecision

using namespace std;

void avgOfLevel(Node *root) {
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        queue<Node *> temp;
        int sum = 0, count = 0;
        while (!q.empty()) {
            count++;
            Node *p = q.front();
            q.pop();
            sum += p->value;
            if (p->left != NULL)
                temp.push(p->left);
            if (p->right != NULL)
                temp.push(p->right);
        }
        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }
        cout << fixed << setprecision(2) << (sum / (count * 1.0)) << " ";
    }
}

//sum tree
// O(n^2)
int Sum(Node *root) {
    if (root == NULL)
        return 0;
    return Sum(root->left) + root->value +
           Sum(root->right);
}

bool isSumTree(Node *root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;
    int leftStr, rightStr;
    leftStr = Sum(root->left);
    rightStr = Sum(root->right);
    return (root->value == leftStr + rightStr) && isSumTree(root->left) && isSumTree(root->right);
}

//O(n)
// Sum Tree
// check for leaf node
bool isLeaf(Node *t) {
    if (t == NULL)
        return false;
    return (t->left == NULL && t->right == NULL);
}

bool checkSum(Node *root) {
    if (root == NULL || isLeaf(root))
        return true;
    int lsum = 0, rsum = 0;
    if (checkSum(root->left) && checkSum(root->right)) {
        // left
        if (root->left == NULL)
            lsum = 0;
        else if (isLeaf(root->left))
            lsum = root->left->value;
        else
            lsum = 2 * root->left->value;

        // right
        if (root->right == NULL)
            rsum = 0;
        else if (isLeaf(root->right))
            rsum = root->right->value;
        else
            rsum = 2 * root->right->value;
        return root->value == rsum + lsum;
    }
    return false;
}

Node *getMirrorImage(Node *root) {
    if (!root)
        return root;
    if (isLeaf(root))
        return root;
    else {
        Node *temp = root->left;
        root->left = getMirrorImage(root->right);
        root->right = getMirrorImage(temp);
        return root;
    }
}
bool areMirror(Node *root1,Node *root2)
{
    if (root1==NULL && root2==NULL)
        return true;
    // If only one is empty
    if (root1==NULL || root2 == NULL)
        return false;
    else{
        return (root1->value == root2->value
            && areMirror(root1->left,root2->right)
            && areMirror(root1->right,root2->left)
            );
    }
}


int findDistinctCount(Node *root,unordered_map<int,int> mp)
{
    if(root == NULL)
        return mp.size();
    mp[root->value]++;
    int max_p = max(findDistinctCount(root->left,mp),findDistinctCount(root->right,mp));
    // remove current node
    mp[root->value]--;
    if(mp[root->value] == 0)
        mp.erase(root->value);
    return max_p;
}
int solve(Node *root){
    if(!root)
        return 0;
    unordered_map<int,int> t;
    return findDistinctCount(root,t);
}
// connvert to sumTree
int convertToSumTree(Node *root)
{
    if(!root)
        return 0;
    int left = convertToSumTree(root->left);
    int right = convertToSumTree(root->right);
    int temp = root->value;
    root->value = left+right;
    return (temp + root->value);
}


// 26 LCA (Least Common Ancestors)
Node *lca(Node *root,int a, int b)
{
    if(!root)
        return NULL;
    if(a == root->value || b == root->value)
        return root;
    Node *left = lca(root->left,a,b);
    Node *right = lca(root->right,a,b);
    if(left && right)
        return root;
    else return (left?left:right);
}
int main() {
    int rv;
//    cout << "Enter root value ";
    cin >> rv;
    Node *root = new Node(rv);
    BinaryTree bt(root);
//    cout << "PreOrder is ";
//    bt.preOrderTraversal(root);
//    cout << "\n";
//    cout << "InOrder is ";
//    bt.inOrderTraversal(root);
//    cout << "\n";
//    cout << "PostOrder is ";
//    bt.postOrderTraversal(root);
//
//    cout << "\n";
//    cout << "\n";
//    cout << Sum(root) << "\n";
//    cout << "Height  = " << bt.height(root) << "\n";
//    cout << "Size  = " << bt.sizeOfTree(root) << "\n";
//    avgOfLevel(root);
//    cout << "LevelOrder is ";
//    bt.levelOrderTraversal(root);
/*
 * For Mirror Tree question has two trees*/
//    cout << "Enter root value ";
//    cin >> rv;
//    Node *root2 = new Node(rv);
//    BinaryTree bt2(root2);
//    cout<<(areMirror(root,root2)?"true":"false")<<"\n";
//    cout<<"Solve "<<solve(root);
    int w = convertToSumTree(root);
    cout<<"Now \n";
    bt.levelOrderTraversal(root);
    return 0;
}

/*
4 1 3 -1 -1 -1 -1
48 12 12 6 6 6 6 -1 -1 -1 -1 -1 -1 -1 -1
5 6 7 3 2 9 -1 -1 -1 -1 -1 -1 -1

check mirror image
 Input
5 4 1 3 2 6 7 -1 -1 -1 -1 -1 -1 -1 -1
5 1 4 7 6 2 3 -1 -1 -1 -1 -1 -1 -1 -1
max distinct
2 7 3 5 3 -1 2 -1 7 2 2 -1 -1 -1 3 -1 -1 -1 -1 -1 -1
 */