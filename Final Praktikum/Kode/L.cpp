#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->key = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->key)
        root->left = insert(root->left, val);
    else if (val > root->key)
        root->right = insert(root->right, val);

    return root;
}

void findValues(Node* node, int level, vector<int>& maxValues) {
    if (node == NULL) {
        return;
    }

    if (level >= maxValues.size()) {
        maxValues.push_back(node->key);
    } else {
        maxValues[level] = max(maxValues[level], node->key);
    }

    findValues(node->left, level + 1, maxValues);
    findValues(node->right, level + 1, maxValues);
}

int main() {
    Node* root = NULL;

    int N;
    while (cin >> N) {
        root = insert(root, N);
    }

    vector<int> number;
    findValues(root, 0, number);

    for (int i = 0; i < number.size(); i++) {
        cout << number[i] << endl;
    }

    return 0;
}
