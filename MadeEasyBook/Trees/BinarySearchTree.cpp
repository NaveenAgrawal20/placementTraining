#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main(){
    BST bst;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int ele;
        cin>>ele;
        bst.addNode(ele);
    }
    cout<<"PreOrder is ";
    bst.preOrderTraversal(bst.root);
    cout<<"\n";
    cout<<"InOrder is ";
    bst.inOrderTraversal(bst.root);
    cout<<"\n";
    cout<<"PostOrder is ";
    bst.postOrderTraversal(bst.root);
    cout<<"\n";
    return 0;
}
/*
8
50 40 60 63 61 35 44 1
*/