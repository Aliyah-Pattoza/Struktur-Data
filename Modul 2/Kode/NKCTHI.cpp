#include <iostream>
#define MAX_INT 100000

using namespace std;

struct TreeNode{
    int val, _parent, _leaf;
    TreeNode *left, *right, *parent;
};

struct BST{
    TreeNode *root;
    unsigned size;
};

TreeNode* create(int value, int dist)
{
    TreeNode* newNode = (TreeNode*) malloc (sizeof(TreeNode));
    newNode->val = value;
    newNode->_parent = dist;
    newNode->_leaf = MAX_INT;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void bst_init(BST* bst)
{
    bst->root = NULL;
    bst->size = 0;
}

TreeNode* insert(TreeNode* root, int value, int dist)
{
    if(root == NULL){
        return create(value, dist);
    }
    if(value < root->val){
        root->left = insert(root->left, value, dist);
        root->left->parent = root;
    }else if(value > root->val){
        root -> right = insert(root->right, value, dist);
        root -> right -> parent = root;
    }
    return root;
}

void bst_insert(BST* bst,int value, int dist)
{
    bst->root = insert(bst->root, value, dist);
    bst->size++;
}

TreeNode* findNode(TreeNode* node, int x)
{
    while (node != NULL) {
        if (x < node->val)
            node = node->left;
        else if (x > node->val)
            node = node->right;
        else
            return node;
    }
    return NULL;
}

TreeNode* findBST(BST* bst, int x)
{
    TreeNode* temp = findNode(bst->root, x);
    if(temp)
        return temp;
    else
        return 0;
}

void solve_from_bottom(TreeNode* node){
    while(node->parent){
        long long temp = node->_leaf + node->_parent;
        node = node->parent;
        if(node->_leaf > temp)
            node->_leaf = temp;
    }
}

void solve_from_top(TreeNode* node){
    if(node){
        if(node->parent){
            long long temp;
            temp = node->parent->_leaf + node->_parent;
            if(node->_leaf > temp)
                node->_leaf = temp;
        }

        solve_from_top(node->left);
        solve_from_top(node->right);
    }
}

void getleaf(TreeNode* node){
    if(node){
        if(node->left || node->right){
            getleaf(node->left);
            getleaf(node->right);
        } else {
            //leaf node
            node->_leaf = 0;
            solve_from_bottom(node);
        }
    }
}

int main()
{
    BST bst;
    bst_init(&bst);
    int N, r;
    cin >> N >> r;
    bst.root = create(r, -1);
    N--;
    while(N--)
    {
        int ai, wi;
        cin >> ai >> wi;
        bst_insert(&bst, ai, wi);
    }
    getleaf(bst.root);
    solve_from_top(bst.root);

    int T;
    cin >> T;

    int out[T], a = 0;

    while(T--)
    {
        int cari;
        cin >> cari;
        TreeNode* res = findBST(&bst, cari);
        if(res)
            out[a++] = res->_leaf;
        else
            out[a++] = 0;
    }
    for(int i = 0; i < a; i++){
        cout << out[i] << " ";
    }
    cout << "\n";
    return 0;
}

/*
10 6
2 3
7 5
1 1
3 3
10 5
4 1
8 8
5 4
9 7
5
1
2
3
4
5
*/
