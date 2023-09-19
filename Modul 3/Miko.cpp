#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
    int height, index=0;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

void avl_init(AVL *avl)
{
    avl->_root = NULL;
    avl->_size = 0u;
}

int _getHeight(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int _getBalanceFactor(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return _getHeight(node->left) - _getHeight(node->right);
}

AVLNode *_rightRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->left;
    pivotNode->left = newParrent->right;
    newParrent->right = pivotNode;

    pivotNode->height = max(_getHeight(pivotNode->left),
                            _getHeight(pivotNode->right)) +
                        1;
newParrent->height = max(_getHeight(newParrent->left),
                             _getHeight(newParrent->right)) +
                         1;

    return newParrent;
}

AVLNode *_leftCaseRotate(AVLNode *node)
{
    return _rightRotate(node);
}

AVLNode *_leftRotate(AVLNode *pivotNode)
{

    AVLNode *newParrent = pivotNode->right;
    pivotNode->right = newParrent->left;
    newParrent->left = pivotNode;

    pivotNode->height = max(_getHeight(pivotNode->left),
                            _getHeight(pivotNode->right)) +
                        1;
  newParrent->height = max(_getHeight(newParrent->left),
                             _getHeight(newParrent->right)) +
                         1;

    return newParrent;
}

AVLNode *_rightCaseRotate(AVLNode *node)
{
    return _leftRotate(node);
}

AVLNode *_leftRightCaseRotate(AVLNode *node)
{
    node->left = _leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode *_rightLeftCaseRotate(AVLNode *node)
{
    node->right = _rightRotate(node->right);
    return _leftRotate(node);
}

AVLNode *_avl_createNode(int value)
{
    AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

AVLNode *_insert_AVL(AVL *avl, AVLNode *node, int value)
{

    if (node == NULL)
        return _avl_createNode(value);
    if (value < node->data)
        node->left = _insert_AVL(avl, node->left, value);
    else if (value > node->data)
        node->right = _insert_AVL(avl, node->right, value);

    node->height = 1 + max(_getHeight(node->left), _getHeight(node->right));

    int balanceFactor = _getBalanceFactor(node);

    if (balanceFactor > 1 && value < node->left->data)
        return _leftCaseRotate(node);
    if (balanceFactor > 1 && value > node->left->data)
        return _leftRightCaseRotate(node);
    if (balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if (balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);

    return node;
}

bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;

    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl, int value)
{
    if (!avl_find(avl, value))
    {
        avl->_root = _insert_AVL(avl, avl->_root, value);
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

int main(){
    AVL Tree;
    avl_init(&Tree);
    int t;
    scanf ("%d", &t);

 while(t--){
        char cmd[1000000];
        int n;
        scanf ("%s %d", cmd, &n);

        string command = cmd;
        if (command == "buat"){
             avl_insert(&Tree, n);
        }

        else if (command == "cari"){
            preorder(Tree._root, 1);
            AVLNode *node = _search(Tree._root, n);
            if (node)
                printf ("Ruangannya ada di urutan ke-%d\n", node->index);
            else
                printf ("Lah, ruangannya mana?\n");
        }

        else{
            printf ("Maksudnya gimana?\n");
        }
}
}
