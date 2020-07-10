#ifndef TREE_H
#define TREE_H
#include <qdebug.h>
#include<iostream>
class node{
public:
    int value;
    node* left;
    node* right;
    int color;
    //int height;
public:
    node(){
        left=NULL;
        right=NULL;
    }
    ~node(){
        delete left;
        delete right;
    }
};
class Tree{
private:
    node* root;
public:
    Tree(){
        node *n1,*n2;
        n1=new node;
        n1->value=1;
        n2=new node;
        n2->value=4;
        n1->left=n2;
        root = new node;
        root->value=3;
        root->left=n1;
    }
    ~Tree(){}
    void InitialTree(){
        node *n1,*n2,*n3;
        n1=new node;
        n1->value=1;
        n2=new node;
        n2->value=4;
        n3=new node;
        n3->value=6;
        n2->right=n3;
        root=new node;
        root->value=3;
        root->left=n1;
        root->right=n2;
    }
    bool isTreeNull(){
        if(root == NULL)return true;
        return false;
    }
    void Ins(int key){
        if(root == NULL){
            root=new node();
            root->value = key;
            return;
        }
        node* currentNode = root;
        node* parentNode = root;
        bool isLeftChild = true;
        while (currentNode != NULL){
            parentNode = currentNode;
            if (key < currentNode->value){
                currentNode = currentNode->left;
                isLeftChild = true;
            }else {
                currentNode = currentNode->right;
                isLeftChild = false;
            }
        }
        node* InsertedNode = new node();
            if (isLeftChild) {
            parentNode->left = InsertedNode;
            }else{
            parentNode->right = InsertedNode;
        }
    }

    int Del(int key){
        node* currentNode = root; //deleted node
        node* parentNode = root;  //parent of deleted node
        bool isLeftChild = true;
        while (currentNode != NULL && currentNode->value != key) {
            parentNode = currentNode;
            if(key < currentNode->value){
                currentNode = currentNode->left;
                isLeftChild = true;
            }else{
                currentNode = currentNode->right;
                isLeftChild = false;
            }
        }
        if (currentNode == NULL) {
            return 0;
        }
        if (currentNode->left == NULL && currentNode->right == NULL) { //leaf
            if (currentNode == root)
                root = NULL;
            else if (isLeftChild)
                parentNode->left = NULL;
            else
                parentNode->right = NULL;
        }else if(currentNode->left == NULL){ //only have right children
            if (currentNode == root)
                root = currentNode->right;
            else if(isLeftChild)
                parentNode->left = currentNode->right;
            else
                parentNode->right = currentNode->right;
        }else if(currentNode->right == NULL){ //only have left children
            if (currentNode == root)
                root = currentNode->right;
            else if(isLeftChild)
                parentNode->left = currentNode->left;
            else
                parentNode->right = currentNode->left;
        }else{ //have two children
            node* maxLeftNode = currentNode->left;
            node* maxLeftNodeParent = currentNode->left;
            if(maxLeftNode->right != NULL)
                maxLeftNode = maxLeftNode->right;
            while(maxLeftNode->right !=NULL){
                maxLeftNodeParent = maxLeftNodeParent->right;
                maxLeftNode = maxLeftNode->right;
            }
            maxLeftNode->left = currentNode->left;
            maxLeftNode->right = currentNode->right;
            maxLeftNodeParent->right = NULL;
            if (currentNode != root){
                parentNode->left = maxLeftNode;
            }
        }
    }

    node* getTree(){
        return root;
    }
};

#endif // TREE_H
