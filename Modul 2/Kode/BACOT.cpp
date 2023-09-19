#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* create(int value)
{
    TreeNode* newNode = (TreeNode*) malloc (sizeof(TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int value)
{
    if (root == NULL) {
        return create(value);
    }
    if (value <= root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    }
    return root;
}

int findNode(TreeNode *root, int value)
{
    if(root == NULL){
        return 0;
    }else if(root->val == value){
        return 1;
    }else if(root->val > value){
        return findNode(root->left, value);
    }else{
        return findNode(root->right, value);
    }
}

int sum2(TreeNode *root, int tot)
{
    if(root==NULL){
        return 0;
    }
    int left = sum2(root->left, tot);
    int right = sum2(root->right, tot);

    if(findNode(root, tot - root->val)){
        return 1;
    }else{
        return left || right;
    }
}

int sum3(TreeNode *root, int tot)
{
    if(root == NULL){
        return 0;
    }
    if(sum2(root, tot - root->val)){
        return 1;
    }

    int left = sum3(root->left, tot);
    int right = sum3(root->right, tot);

    return left || right;
}

int main()
{
    TreeNode *root = NULL;
    int B;
    cin >> B;

    for(int i = 0; i < B; i++){
        int C;
        cin >> C;
        root = insert(root, C);
    }
    int T;
    cin >> T;
    if(findNode(root, T) || sum2(root, T) || sum3 (root, T)){
        cout << "Monggo Lewat..." << endl;
    }else{
        cout << "Wani Piro?" << endl;
    }
    return 0;
}

/*
5
21 12 30 16 8
36

10
50 35 67 75 55 12 43 53 83 60
227
*/
