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
    node root;
public:
    Tree(){
        node *n1,*n2;
        n1=new node;
        n1->value=1;
        n2=new node;
        n2->value=4;
        n1->left=n2;
        root.value=3;
        root.left=n1;
    }
    ~Tree(){}
    void initial(){
        node *n1,*n2,*n3;
        n1=new node;
        n1->value=1;
        n2=new node;
        n2->value=4;
        n3=new node;
        n3->value=6;
        n2->right=n3;
        root.value=3;
        root.left=n1;
        root.right=n2;
    }
    node* getRoot(){
        return &root;
    }
};

#endif // TREE_H
