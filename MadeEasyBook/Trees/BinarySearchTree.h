//
// Created by priya on 7/30/2021.
//

#ifndef MADEEASYBOOK_BINARYSEARCHTREE_H
#define MADEEASYBOOK_BINARYSEARCHTREE_H


class Node{
public:
    int value;
    Node *left;
    Node *right;
    Node(int key){
        value = key;
        left = right = nullptr;
    }
};

class BST {
public:
    Node *root;
    BST(){
        root = NULL;
    }
    Node *insertNode(Node *node,int key){
        if (node == NULL){
            node = new Node(key);
            return node;
        }
        if(key < node->value){
            node->left = insertNode(node->left,key);
        }else{
            node->right = insertNode(node->right,key);
        }
        return node;
    }
    void addNode(int key){
        root = insertNode(root,key);
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
};


#endif //MADEEASYBOOK_BINARYSEARCHTREE_H
