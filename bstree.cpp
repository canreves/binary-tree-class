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

void bstree::insert(int num){
    if(!root){
            root = new node(num);
            return;
        }

        node* ptr1 = root;
        node* ptr2;

        while(ptr1){
            if(num > ptr1->info){
                ptr2 = ptr1;
                ptr1 = ptr1->right;
            }
            else if(num < ptr1->info){
                ptr2 = ptr1;
                ptr1 = ptr1->left;
            }

            else{
                cout<<"Duplicate node error!"<<endl;
                return;
            }
        }
        
        if(ptr2->info > num){
            ptr2->left = new node(num);
        }

        else if(ptr2->info < num){
            ptr2->right = new node(num);
        }
}

node* bstree::copyHelper(node* ptr){
    if(!ptr){
        return nullptr;
    }

    node* newNode = new node(ptr->info);

    newNode->left = copyHelper(ptr->left);
    newNode->right = copyHelper(ptr->right);

    return newNode;
}

bstree::bstree(const bstree & other){
    root = copyHelper(root);
}

bstree & bstree::operator=(const bstree & other){
    if(this == &other){
        return *this;
    }

    if(root){
        delHelper(root);
    }

    root = copyHelper(other.root);
    return *this;
}