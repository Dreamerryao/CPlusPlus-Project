#ifndef TREE_H
#define TREE_H
#include<iostream>
class node{
public:
    int value;
    node* left;
    node* right;
    //for Red-black
    node* parent;
    int color; // 1 is red, 0 is black
    //for AVL
    int height;
    int npl;
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
        root=NULL;
    }
    ~Tree(){}
    void newtree(){
        root=NULL;
    }
    void InitialTree(){
        node *n1,*n2;
        n1=new node;
        n1->value=3;
        n2=new node;
        n2->value=9;
        root = new node;
        root->value=6;
        root->left=n1;
        root->right=n2;
        //for AVL
        n1->height=0;
        n2->height=0;
        root->height = 1;
        //for Red-black
        n1->parent = root;
        n2->parent = root;
        root->parent = NULL;
        root->color = 0;
        n1->color = 1;
        n2->color = 1;
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
        else if(type==9)
            Ins_RBT( key);


    }

    int Del(int key){
            if(type==7)
               return Del_BST(key);
            else if(type==8){
                if(find_key(root,key)==0){
                    return 0;
                }
                root = Del_AVL(root, key);
                return 1;
            }else if(type==9){
                if(find_key(root,key)==0){
                    return 0;
                }
                root = Del_BRT(root, key);
                return 1;
            }
        }

    node* getTree(){
        return root;
    }

    /*BST*/
    int find_key(node *it,int key){
        if(it==NULL){
            return 0;
        }else{
            if(key>it->value){
                return find_key(it->right,key);
            }else if(key<it->value){
                return find_key(it->left,key);
            }else{
                return 1;
            }
        }
    }
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
        //qDebug() << getHeight(T) ;
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

    /*Red-black*/
    node* Ins_RBT( int key){
        if(root == NULL){
            root= new node();
            root->value = key;
            root->color = 0; // black
            root->parent = NULL;
            return root;
        }
        //Ins_BST(key);

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
        //currentNode->parent=parentNode;
        node* InsertedNode = new node();
        InsertedNode->value = key;
        InsertedNode->color = 1;
        InsertedNode->parent=parentNode;
        if (isLeftChild) {
            parentNode->left = InsertedNode;
        }else{
            parentNode->right = InsertedNode;
        }

        FixIns_RBT(InsertedNode);

    }
    node* Del_BRT(node* T, int key){
            node* delNode = find_node(T, key);
            if(delNode==NULL) return T;
            if(delNode==T&&T->left ==NULL && T->right==NULL)
                return NULL;
            node* child;
            node* parent;
            int color;

            if ( (delNode->left!=NULL) && (delNode->right!=NULL) ) {
                node* replace = delNode;

                // get the smallest key in the right tree
                replace = replace->right;
                while (replace->left != NULL)
                    replace = replace->left;

                if (delNode->parent){ // not root
                    if (delNode->parent->left == delNode)
                        delNode->parent->left = replace;
                    else
                        delNode->parent->right = replace;
                }
                else
                    T = replace; // root

                child = replace->right;
                parent = replace->parent;

                color = replace->color; // save color

                if (parent == delNode){
                    parent = replace;
                }
                else{
                    if (child)
                        child->parent = parent;
                    parent->left = child;

                    replace->right = delNode->right;
                    delNode->right->parent = replace;
                }

                replace->parent = delNode->parent;
                replace->color = delNode->color;
                replace->left = delNode->left;
                delNode->left->parent = replace;

                if (color == 0)
                    T = FixDel_RBT(T, child, parent);

                delete delNode;
                return T;
            }

            if (delNode->left !=NULL)
                child = delNode->left;
            else
                child = delNode->right;

            parent = delNode->parent;
            color = delNode->color;

            if (child)
                child->parent = parent;

            if (parent){ // not root
                if (parent->left == delNode)
                    parent->left = child;
                else
                    parent->right = child;
            }
            else
                T = child;

            if (color == 0)
                T = FixDel_RBT(T, child, parent);
            delete delNode;
            return T;

        }
    void FixIns_RBT(node* InsertedNode){
        node *p, *g; //p:parent g:grandparent
        p = InsertedNode->parent;
        while (p && p->color){
            g = p->parent;
            if (p == g->left){
                node *u = g->right; // uncle
                if (u && u->color==1){ // uncle is red
                    u->color=0;
                    p->color=0;
                    g->color=1;
                    InsertedNode = g;
                    continue;
                }
                if (p->right == InsertedNode){ //uncle is black and Inserted is right of p
                    node *tmp;
                    InsertedNode =LRotation(p);
                    tmp = p;
                    p = InsertedNode;
                    InsertedNode = tmp;
                }

                //uncle is black and Inserted is left of p
                p->color=0;
                g->color=1;
                p = RRotation(g);
            }
            else{
                node *u = g->left; // uncle
                if (u && u->color==1){ // uncle is red
                    u->color=0;
                    p->color=0;
                    g->color=1;
                    InsertedNode = g;
                    continue;
                }
                if (p->left == InsertedNode) //uncle is black and Inserted is left of p
                {
                    node *tmp;
                    InsertedNode = RRotation(p);
                    tmp = p;
                    p = InsertedNode;
                    InsertedNode = tmp;
                }

                //uncle is black and Inserted is right of p
                p->color=0;
                g->color=1;
                p = LRotation(g);
            }
        }
        root->color = 0;
    }
    node* LRotation(node* p){
        node *x = p->right;
        p->right = x->left;
        if (x->left != NULL)
            x->left->parent = p;

        x->parent = p->parent;

        if (p->parent == NULL){
            root = x;
        }
        else{
            if (p->parent->left == p)
                p->parent->left = x;
            else
                p->parent->right = x;
        }
        x->left = p;
        p->parent = x;
        return x;
    }
    node* RRotation(node* p){
        node *x = p->left;
        p->left = x->right;
        if (x->right != NULL)
            x->right->parent = p;

        x->parent = p->parent;

        if (p->parent == NULL){
            root = x;
        }
        else{
            if (p == p->parent->right)
                p->parent->right = x;
            else
                p->parent->left = x;
        }

        x->right = p;
        p->parent = x;
        return x;
    }

    node* find_node(node* T, int key){
        if(T==NULL){
            return T;
        }else{
            if(key>T->value){
                return find_node(T->right,key);
            }else if(key<T->value){
                return find_node(T->left,key);
            }else{
                return T;
            }
        }
    }

    node* FixDel_RBT(node* T, node* DelNode, node* parent){
            node* other;
            while ((!DelNode || DelNode->color==0) && DelNode != T){
                if (parent->left == DelNode){
                    other = parent->right;
                    if (other->color==1){
                        // x's sibling is red
                        other->color = 0;
                        parent->color = 1;
                        LRotation(parent);
                        other = parent->right;
                    }
                    if ((!other->left || other->left->color==0) &&
                        (!other->right || (other->right->color==0))){

                        // x's sibling is black and his kids are black
                        other->color = 1;
                        DelNode = parent;
                        parent = DelNode->parent;
                    }else{
                        if (!other->right || other->right->color == 0){
                            // x's sibling is black, left kid is red, right is black
                            other->left->color = 0;
                            other->color = 1;
                            RRotation(other);
                            other = parent->right;
                        }

                        // x's sibling is black, left kid is black
                        other->color = parent->color;
                        parent->color = 0;
                        other->right->color = 0;
                        LRotation(parent);
                        DelNode = root;
                        break;
                    }
                }else{
                    other = parent->left;
                    if (other->color==1){
                        // x's sibling is red
                        other->color = 0;
                        parent->color = 1;
                        RRotation(parent);
                        other = parent->left;
                    }
                    if ((!other->left || other->left->color==0) &&
                        (!other->right || other->right->color==0)){
                        // x's sibling is black and two kids are black/
                        other->color = 1;
                        DelNode = parent;
                        parent = DelNode->parent;
                    }else{
                        if (!other->left || other->left->color==0)
                        {
                            // x's sibling is black, left kid is red, right is black
                            other->right->color=0;
                            other->color=1;
                            LRotation(other);
                            other = parent->left;
                        }
                         // x's sibling is black, right kid is red
                        other->color = parent->color;
                        parent->color = 0;
                        other->left->color = 0;
                        RRotation(parent);
                        DelNode = root;
                        break;
                    }
                }
            }
            if (DelNode)
                DelNode->color=0;
            return T;
        }

};

#endif // TREE_H
