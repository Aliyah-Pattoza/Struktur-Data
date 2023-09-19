#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* create(int value) {
    TreeNode* newNode = (TreeNode*) malloc (sizeof(TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int value) {
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

int Level(TreeNode* node, int value, int level)
{
    if(node == NULL){
        return -1;
    }
    if(node->val == value){
        return level;
    }
    int left = Level(node->left, value, level+1);
    int right = Level(node->right, value, level+1);

    if(left != -1){
        return left;
    }
    return right;
}

int Lca(TreeNode* node, int x, int y)
{
    if(node == NULL){
        return -1;
    }
    if(node->val > x && node->val > y){
        return Lca(node->left, x, y);
    }
    else if(node->val < x && node->val < y){
        return Lca(node->right, x, y);
    }
    else{
        return node->val;
    }
}

int main() {
    int n;
    cin >> n; // Membaca input jumlah node dalam pohon biner
    TreeNode* root = NULL; // Membuat pointer root yang awalnya NULL
    for (int i = 0; i < n; i++) {
        int arr;
        cin >> arr; // Membaca input nilai node
        root = insert(root, arr); // Memanggil fungsi insert untuk menyisipkan node dalam tree
    }
    int q;
    cin >> q; // Membaca input jumlah query
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k; // Membaca input list node
        int nums[k];
        for (int j = 0; j < k; j++) {
            cin >> nums[j]; // Membaca input nilai node dalam query
        }
        int L = nums[0]; // Menginisialisasi nilai L sebagai node pertama dalam query
        for(int j = 1; j < k; j++){
            L = Lca(root, L, nums[j]); // Memanggil fungsi Lca untuk mencari nenek moyang terendah dari node dalam query
        }
        int level = Level(root, L, 1); // Memanggil fungsi Level untuk mencari level dari node L dalam pohon
        cout << L << " " << level - 1 << endl; // Menampilkan hasil nenek moyang terendah dan levelnya
    }
    return 0;
}

/*
12
5 2 3 9 7 25 6 8 20 22 21 23
2
2
20 23
3
8 21 23
*/
