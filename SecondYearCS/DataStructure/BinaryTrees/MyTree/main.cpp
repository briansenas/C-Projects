#include <iostream>
#include <assert.h>
#include <random>
#include <queue>
#include <algorithm>
using namespace std;

///Basic structure of a tree. ( Pointers such in a Linked list ).
template<class T>
struct BstNode{
    T data;
    BstNode* left = 0;
    BstNode* right = 0;

};

// #########################################################################

template<class T>
BstNode<T>* NewNode(T data){
    BstNode<T>* newNode = new BstNode<T>();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// #########################################################################
template<class T>
BstNode<T>* Insert(BstNode<T>* root, T data){
    if(root==NULL)
        root = NewNode(data);
    else if(root->data >= data) {
        root->left = Insert(root->left,data);
    }
    else if(root->data <= data ) {
       root->right = Insert(root->right,data);
    }
    return root;
}


// #########################################################################
template<class T>
void PreOrden(BstNode<T>* root){
    if(root != NULL ) {
        cout << root->data << " ";
        PreOrden(root->left);
        PreOrden(root->right);
    }
}

// #########################################################################
template<class T>
void LevelOrden(BstNode<T>* root){
    assert(root!=NULL);
    queue<BstNode<T>*> Q;
    Q.push(root);
    while(!Q.empty()){
        BstNode<T>* current = Q.front();
        cout << current->data << " ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }
}

// #########################################################################
template<class T>
void InOrden(BstNode<T>* root){
    if(root != NULL){
        InOrden(root->left);
        cout << root->data << " ";
        InOrden(root->right);
    }
}


// #########################################################################
template<class T>
void PostOrden(BstNode<T>* root){
    if(root != NULL){
        PostOrden(root->left);
        PostOrden(root->right);
        cout << root->data << " ";
    }
}

// #########################################################################
template<class T>
bool Search(BstNode<T>* root, T data){
    bool res;
    if(root == NULL) res = false;
    else if(data == root->data)
        res = true;
    else if(data < root->data)
        res = Search(root->left, data);
    else
        res = Search(root->right,data);
    return res;
}

// #########################################################################
template<class T>
T FindMin(BstNode<T>* root){
    assert(root!=NULL);
    BstNode<T>* current = root;
    while(current->left != NULL){ //Or if root->left == NULL return root->data
        current = current->left;
    } // And else the comment not verified, we call FindMind(root->left);
    return current->data;
}

// #########################################################################
//We could apply the same recursive logic here but who cares anyway.
template<class T>
T FindMax(BstNode<T>* root){
    assert(root!=NULL);
    BstNode<T>* current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return current->data;
}


// #########################################################################
template<class T>
int FindHeight(BstNode<T>* root){
    if(root == NULL)
        return -1;
    return max(FindHeight(root->left),FindHeight(root->right))+1;
}

// #########################################################################
template<class T>
BstNode<T>* Delete(BstNode<T>* root, int data){
    assert(root!=NULL);
    if(data < root->data)
        root->left = Delete(root->left,data);
    else if(data>root->data)
        root->right = Delete(root->right,data);
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
            return root;
        }
        else if(root->left == NULL){
            BstNode<T>* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            BstNode<T>* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            T min = FindMin(root->right);
            root->right = Delete(root->right, min);
            root->data = min;
        }
    }
    return root;
}

// #########################################################################

/// Lets think of AVL tree, first of all, lest figure out rotations.
template<class T>
BstNode<T>* rotateRight(BstNode<T>* root){
    BstNode<T>* temp = root->left;
    root->left = root->left->right;
    temp->right = root;
    return temp;
}

template<class T>
BstNode<T>* rotateLeft(BstNode<T>* root){
    BstNode<T>* temp = root->right;
    root->right = root->right->left;
    temp->left = root;
    return temp;
}

// #########################################################################
int main(){
    BstNode<int>* root = NULL;
    root = Insert(root,20);
    root = Insert(root,10);
    root = Insert(root,30);
    root = Insert(root, 5);
    root = Insert(root,35);
    root = Insert(root,15);
    root = Insert(root,25);


    cout << "############ LEVEL-ORDEN ##################" << endl;
    LevelOrden(root);
    cout << endl;

    cout << "############ PRE-ORDEN ##################" << endl;
    PreOrden(root);
    cout << endl;

    cout << "############ IN-ORDEN ##################" << endl;
    InOrden(root);
    cout << endl;

    cout << "############ POST-ORDEN ##################" << endl;
    PostOrden(root);
    cout << endl;


    cout << "########### Other Functions ##############" << endl;
    cout << "El minimo es: " << FindMin(root) << endl;
    cout << "El maximo es: " << FindMax(root) << endl;
    cout << "La altura es: " << FindHeight(root) << endl;
    int valor = 10;
    cout << "Vamos a probar a borrar el valor: " << valor << endl;

    root = Delete(root,valor);

    cout << "############ LEVEL-ORDEN ##################" << endl;
    LevelOrden(root);
    cout << endl;

    cout << "############ PRE-ORDEN ##################" << endl;
    PreOrden(root);
    cout << endl;

    cout << "############ IN-ORDEN ##################" << endl;
    InOrden(root);
    cout << endl;

    cout << "############ POST-ORDEN ##################" << endl;
    PostOrden(root);
    cout << endl;

    cout << "############ Testing My AVL Rotations #############" << endl;
    BstNode<int>* avl = NULL;
    cout << "Original: ";
    avl = Insert(avl,4);
    avl = Insert(avl,5);
    avl = Insert(avl,2);
    avl = Insert(avl,3);
    avl = Insert(avl,1);
    PreOrden(avl);
    cout << endl;
    cout << "Right Rotation: ";
    avl = rotateRight(avl);
    PreOrden(avl);
    cout << endl;
    cout << "Left Rotation: ";
    avl = rotateLeft(avl);
    PreOrden(avl);
    cout << endl;

    cout << "### Testing the Insertions on AVL using the Rotations ####" << endl;
    // Basically for this I have to assure myself of the Balance = | HL(r) - HR(r) | <= 1
    //Plus differentiate between some other problems such as left-right or right-left based on
    //Wether the left height is greater than the right or not. ( Apply the same for the opposite ).
}
// #########################################################################
