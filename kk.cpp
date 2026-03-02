#include <iostream>
#include <vector>

using namespace std;

struct node{
    int info;
    node* right;
    node* left;

    node(int i = 0, node* r = nullptr , node* l = nullptr): info(i), right(r), left(l){}
};


class bstree{
    private:

    node* root;

    void delHelper(node* ptr){
        if(ptr){
            
            delHelper(ptr->left);
            delHelper(ptr->right);
            delete ptr;
            
        }
        
    }

    public:

    bstree() : root(nullptr) {
        cout<<"Empty binary tree is constructed!"<<endl;
    }
    

    ~bstree(){
        if(root){
            delHelper(root);
        }
    }

    void insert(int num){
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

};

int main(){

    cout<<"ece"<<endl;

    return 0;
}