#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

struct BST {
    BSTNode *_root;
    unsigned int _size;

    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;

        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void traverseInorder(vector<int> &result) {
        __inorder(_root, result);
    }

    bool searching(int value, vector<string> &path) {
        BSTNode *temp = searchingval(_root, value, path);
        if (!temp)
            return false;

        if (temp->key == value) {
            return true;
        } else
            return false;
    }

private:
    BSTNode *__createNode(int value) {
        BSTNode *newNode = new BSTNode();
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BSTNode *__search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode *searchingval(BSTNode *root, int value, vector<string> &path) {
        while (root != NULL) {
            if (value < root->key) {
                root = root->left;
                path.push_back("L");
            } else if (value > root->key) {
                root = root->right;
                path.push_back("R");
            } else
                return root;
        }
        return root;
    }

    BSTNode *__insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);

        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);

        return root;
    }

    void __inorder(BSTNode *root, vector<int> &result) {
        if (root) {
            __inorder(root->left, result);
            result.push_back(root->key);
            __inorder(root->right, result);
        }
    }
};

int getLevel(BSTNode *root, int value) {
    BSTNode *node;
    if (root == NULL)
        return 0;

    queue<BSTNode *> n;
    int currLevel = 1;

    n.push(root);
    while (!n.empty()) {
        int size = n.size();
        while (size--) {
            node = n.front();
            if (node->key == value)
                return currLevel;

            n.pop();

            if (node->left != NULL)
                n.push(node->left);

            if (node->right != NULL)
                n.push(node->right);
        }
        currLevel++;
    }
    return 0;
}

int main() {
    BST set;
    int num;
    set.init();
    string command;
    vector<string> path;

    while (cin >> command) {
        if (command == "STOP") {
            cout << "done";
            break;
        } else if (command == "IN") {
            cin >> num;
            set.insert(num);
        } else if (command == "RK") {
            cin >> num;
            vector<int> inorder;
            set.traverseInorder(inorder);
            if (num > 0 && num <= inorder.size()) {
                cout << inorder[num - 1] << endl;
            } else {
                cout << "-1" << endl;
            }
        } else if (command == "FD") {
            cin >> num;
            int level = getLevel(set._root, num);
            if (level) {
                cout << "on level " << level << endl;
            } else {
                cout << "no " << num << endl;
            }
        } else if (command == "PH") {
            cin >> num;
            bool flag = set.searching(num, path);
            if (flag) {
                for (int i = 0; i < path.size(); i++) {
                    cout << path[i];
                }
                cout << endl;
            } else {
                cout << "no " << num << endl;
            }
            path.clear();
        }
    }

    return 0;
}
