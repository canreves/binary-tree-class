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

    public:

    bstree() : root(nullptr){}
    

    ~bstree();

    void insert(int num);
};