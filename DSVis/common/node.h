#ifndef NODE_H
#define NODE_H
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
#endif // NODE_H
