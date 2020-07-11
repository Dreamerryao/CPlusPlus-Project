#ifndef TREE_H
#define TREE_H
#include <qdebug.h>
#include<iostream>
#include<QDebug>
class node{
public:
    int value;
    node* left;
    node* right;
    int color;
    int height;
public:
    node(){
        left=NULL;
        right=NULL;
        height=0;
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
        n1->value=3;
        n2=new node;
        n2->value=9;
        root = new node;
        root->value=6;
        root->left=n1;
        root->right=n2;
        n1->height=0;
        n2->height=0;
        root->height = 1;
        //qDebug() << getHeight(root) <<endl;
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
    void Ins(int key){ //
        if(type==7)
            Ins_BST(key);
        else if(type==8)
            root = Ins_AVL(root, key);

    }

    int Del(int key){
        if(type==7)
           return Del_BST(key);
        else if(type==8)
            root = Del_AVL(root, key);
    }

    node* getTree(){
        return root;
    }

    /*BST*/
    void Ins_BST(int key){
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
    int Del_BST(int key){
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

    /*AVL*/
    node* Ins_AVL(node* T, int key){
        if(T==NULL){
            T=new node(); //height = 0;
            T->value=key;
            qDebug() << getHeight(T) ;
            return T;
        }else if(key<T->value){
            T->left=Ins_AVL(T->left, key);
            if(IsRotate(T)){
                T = RotateTree(T, key);
            }
        }else if(key>T->value){
            T->right=Ins_AVL(T->right, key);
            if(IsRotate(T)){
                T = RotateTree(T, key);
            }
        }
        T->height=max(getHeight(T->left), getHeight(T->right))+1;
        qDebug() << getHeight(T) ;
        return T;
    }
    node* Del_AVL(node* T, int key){
        if (T == NULL)
            return T;
        if ( key < T->value )
            T->left = Del_AVL(T->left, key);
        else if( key > T->value )
            T->right = Del_AVL(T->right, key);
        else{ // key == T->value
            if( (T->left == NULL) ||(T->right == NULL) ){
                node* temp = T->left ?T->left :T->right;
                if (temp == NULL){ // no child
                    T = NULL;
                    return T;
                }
                else // one child
                    *T = *temp;
                delete temp;
            }
            else{ // two
                node* temp = minValueNode(T->right);
                T->value = temp->value;
                T->right = Del_AVL(T->right, temp->value);
            }
        }

        T->height = max(getHeight(T->left),getHeight(T->right))+1;

        int balance = getBalance(T);
        if (balance > 1 && getBalance(T->left) >= 0)
            return LLRotation(T);
        if (balance > 1 && getBalance(T->left) < 0)
            return LRRotation(T);
        if (balance < -1 && getBalance(T->right) <= 0)
            return RRRotation(T);
        if (balance < -1 && getBalance(T->right) > 0)
            return RLRotation(T);

        return T;
    }
    bool IsRotate(node* T){
        if((getHeight(T->left)-getHeight(T->right))==2 || (getHeight(T->right)-getHeight(T->left))== 2){
            return 1;
        }
        return 0;
    }
    node* RotateTree(node* T, int key){
        if(key < T->value){
            if(key < T->left->value){
                T = LLRotation(T);
            }else{
                T = LRRotation(T);
            }
        }else if(key > T->value){
            if(key < T->right->value){
                T = RLRotation(T);
            }else{
                T = RRRotation(T);
            }
        }
        return T;
    }
    node* RRRotation(node* T){
        node* TempNode = T;
        T = T->right;
        TempNode->right = T->left;
        TempNode->height = max(getHeight(TempNode->left),getHeight(TempNode->right))+1;
        T->left = TempNode;
        T->height = max(getHeight(T->left),getHeight(T->right))+1;
        return T;
    }
    node* LLRotation(node* T){
        node* TempNode = T;
        T = T->left;
        TempNode->left = T->right;
        TempNode->height = max(getHeight(TempNode->left),getHeight(TempNode->right))+1;
        T->right = TempNode;
        T->height = max(getHeight(T->left),getHeight(T->right))+1;
        return T;
    }
    node* LRRotation(node* T){
        T->left =RRRotation(T->left);
        T = LLRotation(T);
        return T;
    }
    node* RLRotation(node* T){
        T->right =LLRotation(T->right);
        T = RRRotation(T);
        return T;
    }
    int getHeight(node* T){
        if(T==NULL) return -1;
        else if(T->left==NULL && T->right==NULL) return 0;
        else if(T->left!=NULL && T->right==NULL) return getHeight(T->left) +1;
        else if(T->left==NULL && T->right!=NULL) return getHeight(T->right) +1;
        else return max(getHeight(T->left), getHeight(T->right))+1;
    }
    int max(int x, int y){
        return x > y ? x : y;
    }
    int getBalance(node *N){
        if (N == NULL)
            return 0;
        return getHeight(N->left) -getHeight(N->right);
    }
    node * minValueNode(node* N){
        node* current = N;
        while (current->left != NULL)
            current = current->left;

        return current;
    }
};

#endif // TREE_H
