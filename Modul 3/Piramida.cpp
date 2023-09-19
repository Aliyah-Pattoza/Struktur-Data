#include <iostream>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int val) {
    if (node == NULL) {
        return createNode(val);
    }
    if (val < node->val) {
        node->left = insert(node->left, val);
    } else if (val > node->val) {
        node->right = insert(node->right, val);
    }
    return node;
}

int getHeight(struct Node* node) {
    if (node == NULL) {
        return -1;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int isBalanced(struct Node* node) {
    if (node == NULL) {
        return 1;
    }
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right)) {
        return 1;
    }
    return 0;
}

int main() {
    int n, x;
    scanf("%d", &n);
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d", &x);
    root = insert(root, x);
    if (isBalanced(root)) {
        printf("Tree tetap balance\n");
    } else {
        printf("Tree tidak balance\n");
    }
    return 0;
}
