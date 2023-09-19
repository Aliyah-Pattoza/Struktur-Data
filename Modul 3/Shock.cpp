#include <iostream>

using namespace std;

struct Node {
    int val;
    int height;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int get_height(Node* node) {
    return node ? node->height : 0;
}

int get_balance_factor(Node* node) {
    return node ? get_height(node->left) - get_height(node->right) : 0;
}

void update_height(Node* node) {
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    node->height = max(left_height, right_height) + 1;
}

Node* rotate_right(Node* node) {
    Node* new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;
    update_height(node);
    update_height(new_root);
    return new_root;
}

Node* rotate_left(Node* node) {
    Node* new_root = node->right;
    node->right = new_root->left;
    new_root->left = node;
    update_height(node);
    update_height(new_root);
    return new_root;
}

Node* balance(Node* node) {
    if (!node)
        return node;

    update_height(node);

    int balance_factor = get_balance_factor(node);

    if (balance_factor > 1) {
        if (get_balance_factor(node->left) < 0)
            node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if (balance_factor < -1) {
        if (get_balance_factor(node->right) > 0)
            node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

Node* insert(Node* node, int val) {
    if (!node)
        return new Node(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);

    return balance(node);
}

void in_order_traversal(Node* node) {
    if (!node)
        return;
    in_order_traversal(node->left);
    cout << node->val << " ";
    in_order_traversal(node->right);
}

// fungsi untuk mencari parent dari suatu node dalam AVL tree
Node* get_parent(Node* node, Node* child) {
    if (node == nullptr || node == child)
        return nullptr;

    if ((node->left == child) || (node->right == child))
        return node;

    if (child->val < node->val)
        return get_parent(node->left, child);

    return get_parent(node->right, child);
}

Node* get_sibling(Node* root) {
    Node* parent = get_parent(root , node);
    if (parent == nullptr)
        return nullptr;

    if (parent->left == node)
        return parent->right;

    return parent->left;
}

Node* get_sibling_parent(Node* node) {
    Node* parent = get_parent(root, node);
    if (parent == nullptr)
        return nullptr;

    return get_sibling(parent);
}

int get_sibling_parent_val(Node* node) {
    Node* sibling_parent = get_sibling_parent(node);
    if (sibling_parent == nullptr)
        return -1;

    return sibling_parent->val;
}

int get_sibling_parent_val(Node* node) {
    if (node == nullptr || node == root)
        return -1;

    Node* parent = get_parent(root, node);
    Node* grandparent = get_parent(root, parent);

    if (grandparent == nullptr)
        return -1;

    if (grandparent->left == parent)
        return grandparent->right ? grandparent->right->val - parent->val : -1;

    return grandparent->left ? grandparent->left->val - parent->val : -1;
}


int main() {
    int n, t;
    cin >> n >> t;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    for (int i = 0; i < t; i++) {
        int val;
        cin >> val;
        Node* node = root;
        while (node) {
            if (node->val == val) {
                Node* parent = get_parent(root, node);
                int sibling_parent_val = get_sibling_parent_val(node);
                if (parent == nullptr || sibling_parent_val == -1)
                    cout << parent->val << endl;
                else
                    cout << abs(parent->val - sibling_parent_val) << endl;
                break;
            } else if (node->val > val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }

    return 0;
}
