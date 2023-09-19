#include <iostream>
#include <queue>
using namespace std;

struct BSTNode {
    int key;
    BSTNode *parent;
    BSTNode *left, *right;
};

struct BST {
    BSTNode* _root;
    unsigned int _size;
};

BSTNode* create(int value) {
    BSTNode* newNode = new BSTNode();
    newNode->key = value;
    newNode->parent = 0;
    newNode->left = newNode->right = 0;
    return newNode;
}

BSTNode* insert(BSTNode* root, int value) {
    if (root == nullptr)
        return create(value);
    if (value < root->key) {
        root->left = insert(root->left, value);
        root->left->parent = root;
    } else if (value > root->key) {
        root->right = insert(root->right, value);
        root->right->parent = root;
    }

    return root;
}

void bst_traverse(BSTNode* root, int num, bool& found) {
    if (!found && root && (root->left || root->right)) {
        queue<BSTNode*> nodeQueue;
        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            BSTNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (currentNode->left && currentNode->right) {
                int currentSum = currentNode->key + currentNode->left->key + currentNode->right->key;
                if (currentSum == num || currentSum == (currentNode->key + currentNode->parent->key + currentNode->right->key) ||
                    currentSum == (currentNode->key + currentNode->left->key + currentNode->parent->key)) {
                    found = true;
                    break;
                }
            } else if (currentNode->left) {
                if (currentNode->parent && num == (currentNode->key + currentNode->parent->key + currentNode->left->key)) {
                    found = true;
                    break;
                }
            } else if (currentNode->right) {
                if (currentNode->parent && num == (currentNode->key + currentNode->parent->key + currentNode->right->key)) {
                    found = true;
                    break;
                }
            }
            if (currentNode->left) {
                nodeQueue.push(currentNode->left);
            }
            if (currentNode->right) {
                nodeQueue.push(currentNode->right);
            }
        }
    }
}

void bst_init(BST* bst) {
    bst->_root = nullptr;
    bst->_size = 0u;
}

bool bst_isEmpty(BST* bst) {
    return bst->_root == nullptr;
}

void bst_insert(BST* bst, int value) {
    bst->_root = insert(bst->_root, value);
    bst->_size++;
}

void traverse(BST* bst, int num, bool& found) {
    found = false;
    if (bst->_root)
        bst_traverse(bst->_root, num, found);
}

int main() {
    BST mytree;
    bst_init(&mytree);
    int N, K;
    cin >> N;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        sum += P;
        bst_insert(&mytree, P);
    }

    cin >> K;
    bool found = 0;
    if (sum == K) {
        found = 1;
    } else {
        traverse(&mytree, K, found);
    }
    if (found) {
        cout << K << " Selamat! Kalian menemukan harta karunnya" << endl;
    } else {
        cout << K << " Tidak ada kombinasi yang tepat! Bikin ulang." << endl;
    }

    return 0;
}
