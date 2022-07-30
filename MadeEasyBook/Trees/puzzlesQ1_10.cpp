#include <iostream>
#include "BinaryTree.h"
#include <stack>
#include <queue>
#include <map>
using namespace std;

void printArr(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

typedef long long ll;

// Q1-2 Max Rec and Iter
ll rec_maxT(Node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->value;
    int left = rec_maxT(root->left);
    int right = rec_maxT(root->right);
    return max(max(left, right), (int) root->value);
}

ll maxT(Node *root) {
    int max = root->value;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *t = q.front();
        q.pop();
        if (max < t->value) {
            max = t->value;
        }
        if (t->left != nullptr) {
            q.push(t->left);
        }
        if (t->right != nullptr) {
            q.push(t->right);
        }
    }
    return max;
}

int iter_height(Node *root) {
    if (!root)
        return 0;
    int h = 0; // height or level
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        root = q.front();
        q.pop();
        // current level is completed
        if (root == NULL) {
            if (!q.empty()) {
                q.push(NULL);
            }
            h++;
        } else {
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
    }
    return h;
}

//Q 18 = Diameter of tree (no of nodes on longest Path)
int diameter(Node *root) {
    int leftHeight, rightHeight, leftDia, rightDia;
    if (root == NULL)
        return 0;
    leftHeight = iter_height(root->left);
    rightHeight = iter_height(root->right);
    leftDia = diameter(root->left);
    rightDia = diameter(root->right);
    return max(leftHeight + rightHeight + 1, max(leftDia, rightDia));
}

//Q 20 print all path to leaf
void pathToLeaf(Node *root, int path[], int pathLen) {
    if (!root)
        return;
    path[pathLen] = root->value;
    pathLen++;
    if (root->left == NULL && root->right == NULL)
        printArr(path, pathLen);
    else {
        pathToLeaf(root->left, path, pathLen);
        pathToLeaf(root->right, path, pathLen);
    }
}

// Q 21 Sum exists from root to any node ?
//https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/
bool sumExists(Node *root, int sum) {
    if (root == NULL)
        return (sum == 0);

    // for root to leaf node // remove this condition
    if (sum == 0)
        return true;
        //
    else {
        sum = sum - root->value;
        if ((root->left && root->right) || (!root->left && !root->right)) {
            return sumExists(root->left, sum) || sumExists(root->right, sum);
        } else if (root->left)
            return sumExists(root->left, sum);
        else
            return sumExists(root->right, sum);
    }
}

// 26 LCA (Least Common Ancestors)
Node *lca(Node *root, int a, int b) {
    if (!root)
        return NULL;
    if (a == root->value || b == root->value)
        return root;
    Node *left = lca(root->left, a, b);
    Node *right = lca(root->right, a, b);
    if (left && right)
        return root;
    else return (left ? left : right);
}

// ZigZag
void zigZag(Node *root) {
    stack<Node *> currentLevel, nextLevel;
    bool leftToRight = true;
    currentLevel.push(root);
    while (!currentLevel.empty()) {
        Node *temp = currentLevel.top();
        currentLevel.pop();
        if (temp) {
            cout << temp->value << " ";
            if (leftToRight) {
                if (temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            } else {
                if (temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }
        }
        if (currentLevel.empty()) {
            swap(currentLevel, nextLevel);
            leftToRight = false;
        }
    }
}

// Q vertical sum
void getVerticalSum(Node *root,int column,map<int,int>& hash)
{
    if(!root)
        return;
    hash[column] += root->value;
    getVerticalSum(root->left,column - 1,hash);
    getVerticalSum(root->right,column + 1,hash);
}

void verticalSum(Node *root){
    map<int,int> hash;
    getVerticalSum(root,0,hash);
    cout<<"\nVertical sum = \n";
    for(auto e: hash){
        cout<<e.second<<" ";
    }
}

// min depth
int minDepth(Node *root){
    if(!root)
        return 0;
    if(root->left == NULL || root->right == NULL)
        return minDepth(root->left) + minDepth(root->right) + 1;
    int mleftD = minDepth(root->left);
    int mrightD = minDepth(root->right);
    return ((mleftD < mrightD) ? mleftD : mrightD )+1;
}

int main() {
    int v;
    cin >> v;
    Node *root = new Node(v);
    BinaryTree bt(root);
    bt.allTravesal(root);
    cout << "Max = " << rec_maxT(root) << endl;
    cout << "Max = " << rec_maxT(root) << endl;
    cout << "Height = " << iter_height(root) << endl;
    cout << "Dia = " << diameter(root) << endl;
    int path[20];
    pathToLeaf(root, path, 0);
    cout << (sumExists(root, 18) ? "True" : "False") << endl;
    cout << lca(root, 4, 6)->value<<"\n";
    cout<<"ZigZag Traversal ";zigZag(root);
    verticalSum(root);
    cout<<"\nMin depth = " << minDepth(root) <<" \n";
    return 0;
}
/*
4 1 3 -1 -1 -1 -1
48 12 12 6 6 6 6 -1 -1 -1 -1 -1 -1 -1 -1
5 6 7 3 2 9 -1 -1 -1 -1 -1 -1 -1
2 7 3 5 3 -1 2 -1 7 2 2 -1 -1 -1 3 -1 -1 -1 -1 -1 -1
1 2 3 4 5 -1 -1 -1 -1 -1 -1
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
1 2 3 -1 -1 4 5 -1 -1 -1 7 -1 -1
4 -1 6 5 7 -1 -1 -1 -1
*/