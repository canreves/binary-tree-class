#include <iostream>
#include "bstree.h"

using namespace std;


void bstree::delHelper(node* ptr){
    if(ptr){
            delHelper(ptr->left);
            delHelper(ptr->right);
            delete ptr;
        }
}

bstree::bstree(): root(nullptr){}

bstree::~bstree(){
    if(root){
        delHelper(root);
    }
}



