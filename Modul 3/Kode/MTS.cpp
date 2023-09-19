#include<bits/stdc++.h>
using namespace std;

typedef struct AVLNode_t
{
    int val;
    struct AVLNode_t *left,*right;
    int height, index = 0;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

void avl_init(AVL *avl)
{
    avl->_root = NULL;
    avl->_size = 0;
}

AVLNode* create(int v) {
    AVLNode* newNode = new AVLNode();
    newNode->val = v;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(AVLNode* node) {
    if(node == NULL)
        return 0;
    return node->height;
}

int balanceFactor(AVLNode* node) {
    if(node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

AVLNode* rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=max(height(pivotNode->left), height(pivotNode->right))+1;
    newParrent->height=max(height(newParrent->left), height(newParrent->right))+1;

    return newParrent;
}

AVLNode* leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = max(height(pivotNode->left), height(pivotNode->right))+1;
    newParrent->height = max(height(newParrent->left), height(newParrent->right))+1;

    return newParrent;
}

AVLNode* insert(AVL *avl, AVLNode* node, int val) {
    if(node == NULL) {
        return create(val);
    }

    if(val < node->val) {
        node->left = insert(avl, node->left, val);
    }
    else if(val > node->val) {
        node->right = insert(avl, node->right, val);
    }

    node->height = max(height(node->left), height(node->right)) + 1;
    int bf = balanceFactor(node);

    if(bf > 1 && val < node->left->val) { // LL
        return rightRotate(node);
    }
    if(bf < -1 && val > node->right->val) { // RR
        return leftRotate(node);
    }
    if(bf > 1 && val > node->left->val) { // LR
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    else if(bf < -1 && val < node->right->val) { // RL
         node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->val)
            root = root->left;
        else if (value > root->val)
            root = root->right;
        else
            return root;
    }
    return root;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = search(avl->_root, value);
    if (temp == NULL)
        return 0;

    if (temp->val == value)
        return 1;
    else
        return 0;
}

void avl_insert(AVL *avl, int value)
{
    if (!avl_find(avl, value))
    {
        avl->_root = insert(avl, avl->_root, value);
        avl->_size++;
    }
}

AVLNode *_findMinNode(AVLNode *node)
{
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

int preorder(AVLNode *root, int index)
{
    if (root)
    {
        root->index = index;
        index++;
        index = preorder(root->right, index);
        index = preorder(root->left, index);
    }
    return index;
}

int main() {
    AVL avl;
    avl_init(&avl);
    int T;
    cin >> T;

    while (T--) {
        string Q;
        int n;
        cin >> Q;
        cin >> n;

        if (Q == "buat") {
            avl_insert (&avl, n);
        } else if (Q == "cari") {
            preorder(avl._root, 1);
            AVLNode *node = search(avl._root, n);

            if (node)
                cout << "Ruangannya ada di urutan ke-" << node->index <<endl;
            else
                cout << "Lah, ruangannya mana?\n";
        } else {
            cout << "Maksudnya gimana?\n";
        }
    }
    return 0;
}
