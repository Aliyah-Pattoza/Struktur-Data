#include <bits/stdc++.h>
using namespace std;

// Struktur data untuk simpul BST
struct BST {
    int data;          // Nilai data pada simpul
    BST *left, *right; // Pointer ke simpul anak kiri dan anak kanan
};

// Fungsi untuk membuat simpul baru pada BST
BST* newNode(int data) {
    BST* node = new BST();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Fungsi untuk memasukkan nilai ke dalam BST
BST* bst_insert(BST* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = bst_insert(root->left, data);
    } else if (data > root->data) {
        root->right = bst_insert(root->right, data);
    }
    return root;
}

// Fungsi untuk mencari nilai _leaf terkecil dari simpul pada BST
int solve_from_bottom(BST* root) {
    if (root == NULL) {
        return 0;
    }
    return min(solve_from_bottom(root->left), solve_from_bottom(root->right)) + 1;
}

// Fungsi untuk mencari simpul dengan nilai tertentu pada BST dan mengambil nilai _leaf-nya
int findBST(BST* root, int cari) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == cari) {
        return root->_leaf;
    }
    if (cari < root->data) {
        return findBST(root->left, cari);
    }
    return findBST(root->right, cari);
}

int main() {
    BST* bst = NULL; // Deklarasi dan inisialisasi objek bst dari tipe data BST
    int N, r, T;    // Variabel untuk menyimpan input dari pengguna
    cin >> N >> r;   // Membaca nilai N dan r dari input pengguna
    int ai, wi;     // Variabel untuk menyimpan input dari pengguna dalam loop
    for (int i = 0; i < N - 1; i++) { // Loop untuk membaca nilai ai dan wi sebanyak N-1 kali
        cin >> ai >> wi;
        bst = bst_insert(bst, ai); // Memasukkan nilai ai ke dalam BST menggunakan fungsi bst_insert()
    }
    getleaf(bst, r); // Memanggil fungsi getleaf() untuk menghitung dan menyimpan nilai _leaf untuk setiap simpul dalam BST

    cin >> T; // Membaca nilai T dari input pengguna
    int cari; // Variabel untuk menyimpan input dari pengguna dalam loop
    int out[T]; // Array untuk menyimpan hasil pencarian
    for (int i = 0; i < T; i++) { // Loop untuk membaca nilai cari sebanyak T kali
        cin >> cari;
        out[i] = findBST(bst, cari); // Memanggil fungsi findBST() untuk mencari nilai _leaf untuk simpul dengan nilai cari
    }

    for (int i = 0; i < T; i++) { // Loop untuk menampilkan hasil pencarian
        cout << out[i] << endl;
    }

    return 0; // Mengembal
}
