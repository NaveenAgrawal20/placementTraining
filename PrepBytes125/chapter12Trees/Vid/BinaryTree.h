//
// Created by priya on 7/28/2021.
//
#ifndef MADEEASYBOOK_BINARYTREE_H
#define MADEEASYBOOK_BINARYTREE_H
#include <queue>
#include <stack>
typedef long long ll;
class Node{
public:
    ll value;
    Node *left,*right;
    Node(int value){
        this->value = value;
        left = right = nullptr;
    }
};

class BinaryTree{
public:
    BinaryTree(Node* root= nullptr){
        std::queue<Node *> q;
        q.push(root);
        int x;
        while(!q.empty()){
            Node *temp = q.front();q.pop();
            std::cout<<"Enter left child of "<<temp->value<<" : ";
            std::cin>>x;
            if(x != -1){
                Node* newnode = new Node(x);
                temp->left = newnode;
                q.push(newnode);
            }
            std::cout<<"Enter Right child of "<<temp->value<<" : ";
            std::cin>>x;
            if(x != -1){
                Node* newnode = new Node(x);
                temp->right = newnode;
                q.push(newnode);
            }
        }
    }
    void preOrderTraversal(Node *node){
        if(node != NULL){
            std::cout<<node->value<<" ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }
    void inOrderTraversal(Node *node){
        if(node != NULL){
            inOrderTraversal(node->left);
            std::cout<<node->value<<" ";
            inOrderTraversal(node->right);
        }
    }
    void postOrderTraversal(Node *node){
        if(node != NULL){
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            std::cout<<node->value<<" ";
        }
    }
    void levelOrderTraversal(Node *node){
        std::queue<Node *> q;
        if(node != nullptr)
            q.push(node);
        while(!q.empty()){
            Node *temp = q.front();q.pop();
            std::cout<<temp->value<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }

    int height(Node *root){
        // if root height is considered as 0
        if(root == nullptr)
            return -1;
        int x = height(root->left);
        int y = height(root->right);
        return x > y ? x + 1 : y + 1;
    }
    int sizeOfTree(Node *root){
        if(root == nullptr)
            return 0;
        int leftCount = sizeOfTree(root->left);
        int rightCount = sizeOfTree(root->right);
        return leftCount + rightCount + 1;
    }
    void iterPreorder(Node *root)
    {
        std::stack<Node *> s;
        while(true)
        {
            while(root)
            {
                std::cout<<root->value<<" ";
                s.push(root);
                root = root->left;
            }
            if(s.empty())
               break;
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    void iterPost(Node *root)
    {
        std::stack<Node *> s;
        Node *prev = NULL; // track
        do{
            while(root){
                s.push(root);
                root = root->left;
            }
            while(root == NULL && !s.empty())
            {
                root = s.top();
                if(root->right == NULL || prev == root->right){
                    std::cout<<root->value<<" ";
                    s.pop();
                    prev = root;
                    root = NULL;
                } else
                    root = root->right;
            }
        }while(!s.empty());
    }


    void allTravesal(Node *root){
        std::cout<<"Pre ";
        preOrderTraversal(root);
        std::cout<<"\n";
        std::cout<<"Iterative Pre ";
        iterPreorder(root);
        std::cout<<"\n";
        std::cout<<"InOrder ";
        inOrderTraversal(root);
        std::cout<<"\n";
        std::cout<<"Post ";
        postOrderTraversal(root);
        std::cout<<"\n";
        std::cout<<"IterPost ";
        iterPost(root);
        std::cout<<"\n";
        std::cout<<"Level ";
        levelOrderTraversal(root);
        std::cout<<"\n";
//        std::cout<<"";
//        preOrderTraversal(root);
//        std::cout<<"\n";
    }
};


#endif //MADEEASYBOOK_BINARYTREE_H
