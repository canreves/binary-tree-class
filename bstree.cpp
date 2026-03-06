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

bstree::bstree(bstree && other){
    root = other.root;
    other.root = nullptr;
}

bstree & bstree::operator=(bstree && other){
    if(this == &other){
        return *this;
    }

    if(root){
        delHelper(root);
    }

    root = other.root;
    other.root = nullptr;

    return *this;
}

bool bstree::doesExist(int num){
    node* ptr = root;

    while(ptr){
        if(num > ptr->info){
            ptr = ptr->right;
        }
        else if(num < ptr->info){
            ptr = ptr->left;
        }

        else{
            return true;
        }
    }

    return false;
}

void bstree::print_in_order(){
    if(root){
        print_in_order_helper(root);
    }
}

void bstree::print_in_order_helper(node* ptr){
    if(ptr){
        print_in_order_helper(ptr->left);
        cout<<ptr->info<<" ";
        print_in_order_helper(ptr->right);
    }
}

void bstree::print_pre_order(){
    if(root){
        print_pre_order_helper(root);
    }
}

void bstree::print_pre_order_helper(node* ptr){
    if(ptr){
        cout<<ptr->info<<" ";
        print_pre_order_helper(ptr->left);
        print_pre_order_helper(ptr->right);
    }
}

void bstree::print_post_order(){
    if(root){
        print_post_order_helper(root);
    }
}

void bstree::print_post_order_helper(node* ptr){
    if(ptr){
        print_post_order_helper(ptr->left);
        print_post_order_helper(ptr->right);
        cout<<ptr->info<<" ";
    }
}

