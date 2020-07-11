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
    ~node(){}
};
class Tree{
private:
    node* root;
public:
    int type;
    Tree(){
        node *n1,*n2;
        n1=new node;
        n1->value=6;
        n2=new node;
        n2->value=3;
        n1->left=n2;
        root = new node;
        root->value=9;
        root->left=n1;
    }
    ~Tree(){}
    void InitialTree(){
        node *n1,*n2,*n3;
        n1=new node;
        n1->value=6;
        n2=new node;
        n2->value=12;
        n3=new node;
        n3->value=6;
        n2->right=n3;
        root=new node;
        root->value=9;
        root->left=n1;
        root->right=n2;
    }
    bool isTreeNull(){
        if(root == NULL)return true;
        return false;
    }
    void Ins(int key){
        if(type==7){
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
            InsertedNode->value = key;
                if (isLeftChild) {
                parentNode->left = InsertedNode;
                }else{
                parentNode->right = InsertedNode;
            }
        }
//        qDebug()<<"key: "<<key<<endl;

    }

    int Del(int key){
        if(type==7){
            if(root!=NULL && root->left==NULL && root->right==NULL){
                if(root->value==key){
                    root = NULL;
                    return 1;
                }else{
                    return 0;
                }
            }
            node *newroot = root;
            node *presite = root;
            int pos = 0;
            while(root != NULL){
                if(root->value > key){
                    presite = root;
                    root = root->left;
                    pos = -1;
                }
                else if(root->value < key){
                    presite = root;
                    root = root->right;
                    pos = 1;
                }
                else{
                    break;
                }
            }
            if(root == NULL){ //not found
               root = newroot;
               return 0;
            }
            else{
                if(root->left!=NULL && root->right!=NULL){
                    node *Lmax = root->left;
                    node *PreLmax = root;
                    while(Lmax->right != NULL){
                        PreLmax = Lmax;
                        Lmax = Lmax->right;
                    }
                    root->value = Lmax->value;
                    if(PreLmax->left == Lmax)
                        PreLmax->left = Lmax->left;
                    else
                        PreLmax->right = Lmax->left;
                    delete Lmax;
                    Lmax = NULL;
                }
                else if(root->left == NULL && root->right != NULL){
                    if(0 == pos){
                        newroot = root->right;
                    }
                    else if(1 == pos){
                        presite->right = root->right;
                    }
                    else{
                        presite->left = root->right;
                    }
                    delete root;
                    root = NULL;
                }
                else if(root->right == NULL && root->left != NULL){
                    if(0 == pos){
                        newroot = root->left;
                    }
                    else if(1 == pos){
                        presite->right = root->left;
                    }
                    else{
                        presite->left = root->left;
                    }
                    delete root;
                    root = NULL;
                }
                else{
                    if(0 == pos){
                        delete root;
                        root = NULL;
                    }
                    else if(1 == pos){
                        presite->right = NULL;
                        delete root;
                        root = NULL;
                    }
                    else{
                        presite->left = NULL;
                        delete root;
                        root = NULL;
                    }
                }
            }
            root = newroot;
            return 1;
        }

    }

    node* getTree(){
        return root;
    }
};

#endif // TREE_H
