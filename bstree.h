struct node{
    int info;
    node* right;
    node* left;

    node(int i = 0, node* r = nullptr , node* l = nullptr): info(i), right(r), left(l){}
};

class bstree{
    private:
    node* root;
    void delHelper(node* ptr);
    node* copyHelper(node* ptr); 
    void print_in_order_helper(node*);
    void print_pre_order_helper(node*);
    void print_post_order_helper(node*);

    public:
    bstree() : root(nullptr){}
    ~bstree();
    bstree(const bstree &);
    void insert(int num);
    bstree & operator=(const bstree &);
    bstree(bstree &&);
    bstree & operator=(bstree &&);
    bool doesExist(int num);
    void print_in_order();
    
    void print_pre_order();
    void print_post_order();
    



};