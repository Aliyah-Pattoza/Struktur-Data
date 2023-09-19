#include <iostream>
#include <vector>

using namespace std;

struct BSTNode {
    BSTNode *left, *right;
    int key;
    int level;
    string path;
};

BSTNode *createNode(int val, int level, string path) {
    BSTNode *newNode = new BSTNode();
    if(newNode){
        newNode->key = val;
        newNode->left = newNode->right = NULL;
        newNode->level = level;
        newNode->path = path;
    }
    return newNode;
}

BSTNode *search(BSTNode *root, int val) {
    if (root == 0 || root->key == val) {
        return root;
    }
    if (val < root->key) {
        return search(root->left, val);
    }
    return search(root->right, val);
}


BSTNode *insert(BSTNode *root, int val, int level, string path) {
    if (root == 0) {
        return createNode(val, level, path);
    }
    if (val < root->key) {
        string newPath = path + "L";
        root->left = insert(root->left, val, level + 1, newPath);
    } else if (val > root->key) {
        string newPath = path + "R";
        root->right = insert(root->right, val, level + 1, newPath);
    }
    return root;
}

void path(BSTNode* root, int val) {
    BSTNode* Node = search(root, val);
    if (Node == 0) {
        cout << "no " << val << endl;
    } else {
        cout << Node->path << "S" << endl;
    }
}

int number(BSTNode* root, int& x) {
    if (root == 0) {
        return -1;
    }
    int left = number(root->left, x);
    if (left != -1) {
        return left;
    }
    x--;
    if (x == 0) {
        return root->key;
    }

    return number(root->right, x);
}

int main() {
    BSTNode *root = nullptr;
    int num;
    string commands;

    while (cin >> commands && commands != "STOP") {
        if (commands == "IN") {
            cin >> num;
            BSTNode* node = search(root, num);
            if (node == 0) {
                root = insert(root, num, 1, "");
            }
        } else if (commands == "RK") {
            cin >> num;
            int res = number(root, num);
            cout << res << endl;
        } else if (commands == "FD") {
            cin >> num;
            BSTNode* node = search(root, num);
            if (node == 0) {
                cout << "no " << num << endl;
            } else {
                cout << "on level " << node->level << endl;
            }
        } else if (commands == "PH") {
            cin >> num;
            path(root, num);
        }
    }
    cout << "done" << endl;

    return 0;
}
