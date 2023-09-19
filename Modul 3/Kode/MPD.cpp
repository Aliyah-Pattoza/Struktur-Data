#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
    int data;
    Node *left, *right;
}AVL;

AVL* create(int value) {
    AVL* node = (AVL*)malloc(sizeof(AVL));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

AVL* insert(AVL* root, int val) {
    if (root == NULL) {
        return create(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}

int height(AVL* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int isBalanced(AVL* root) {
    if (root == NULL) {
        return 1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return 1;
    }
    return 0;
}

int main() {
    int n, x;
    cin >> n;
    AVL* root = NULL;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }
    cin >> x;
    root = insert(root, x);
    if (isBalanced(root)) {
        cout << "Tree tetap balance\n";
    } else {
        cout << "Tree tidak balance\n";
    }
    return 0;
}
