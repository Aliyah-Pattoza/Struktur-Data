#include <stdio.h>
#include <stdlib.h>
# define MAX_INT 2147483647
//mendefinisikan sebuah konstanta dengan nama MAX_INT dan memiliki nilai 2147483647
typedef struct __node{
    int data, dparent, dleaf;
    struct __node *left, *right, *parent;
} Node;
//mendefinisikan sebuah struktur dengan nama __node yang memiliki beberapa variabel bertipe data int dan pointer ke struct __node
//variabel data menyimpan data node, dparent menyimpan jarak ke parent node, dleaf menyimpan jarak ke leaf node
//pointer left dan right menyimpan pointer ke node anak kiri dan kanan, sedangkan parent menyimpan pointer ke node parent

typedef struct {
    Node *root;
    unsigned __size;
} Bst;
//mendefinisikan sebuah struktur dengan nama Bst yang memiliki variabel root bertipe pointer ke struct __node dan __size bertipe unsigned int

void bst_init(Bst*);
//mendefinisikan sebuah fungsi dengan nama bst_init yang menerima parameter pointer ke struktur Bst dan tidak mengembalikan nilai
void bst_insert(Bst*, int, int);
//mendefinisikan sebuah fungsi dengan nama bst_insert yang menerima parameter pointer ke struktur Bst dan 2 buah nilai bertipe int
Node *createNode(int, int);
//mendefinisikan sebuah fungsi dengan nama createNode yang mengembalikan pointer ke struct __node dan menerima 2 buah nilai bertipe int
Node *find(Bst*, int);
//mendefinisikan sebuah fungsi dengan nama find yang mengembalikan pointer ke struct __node dan menerima 2 buah parameter yaitu pointer ke struktur Bst dan sebuah nilai bertipe int

Node *createNode(int data, int dist){
    Node *newNode = (Node*)malloc(sizeof(Node));
    //membuat sebuah variabel bertipe pointer ke struct __node dengan nama newNode dan mengalokasikan memori sebesar ukuran dari struct __node
    newNode -> data = data;
    newNode -> dparent = dist;
    newNode -> dleaf = MAX_INT;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> parent = NULL;
    //mengisi nilai dari variabel-variabel pada newNode
    return newNode;
    //mengembalikan nilai pointer newNode
}

void bst_init(Bst* bst){
    bst->root = NULL;
    bst->__size = 0;
    //mengisi nilai dari variabel root dan __size pada struktur Bst
}

Node *__rec_bst_insert(Node* root, int data, int dist){
    if(root==NULL)
        return createNode(data, dist);
    //jika root bernilai NULL, maka buat node baru dengan nilai data dan dist lalu kembalikan pointer ke node baru tersebut

    if(data < root->data){
        root -> left = __rec_bst_insert(root->left, data, dist);
        root -> left -> parent = root;
        //jika data kurang dari nilai data root, masukkan data ke anak kiri root dan set parent dari anak kiri tersebut ke root
    }
    else if(data > root->data){
        root -> right = __rec_bst_insert(root->right, data, dist);
        root -> right -> parent = root;
        //jika data lebih dari nilai data root, masukkan data ke anak kanan root dan set parent dari anak kanan tersebut ke root
    }

    return root
