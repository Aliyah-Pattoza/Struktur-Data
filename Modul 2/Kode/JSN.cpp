#include <stdio.h>
#include <stdlib.h>
#define MAX_INT 100000

typedef struct __node{
    int data, dparent, dleaf;
    struct __node *left, *right, *parent;
} Node;

typedef struct {
    Node *root;
    unsigned __size;
} Bst;

Node *createNode(int data, int dist){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> dparent = dist;
    newNode -> dleaf = MAX_INT;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> parent = NULL;
    return newNode;
}

void bst_init(Bst* bst){
    bst->root = NULL;
    bst->__size = 0;
}

Node *__rec_bst_insert(Node* root, int data, int dist){
    if(root==NULL)
        return createNode(data, dist);

    if(data < root->data){
        root -> left = __rec_bst_insert(root->left, data, dist);
        root -> left -> parent = root;
    }
    else if(data > root->data){
        root -> right = __rec_bst_insert(root->right, data, dist);
        root -> right -> parent = root;
    }

    return root;
}

void bst_insert(Bst* bst, int data, int dist){
    bst->root = __rec_bst_insert(bst->root, data, dist);
    bst->__size++;
}

Node *_find(Node *node, int x){
    while (node != NULL) {
        if (x < node->data)
            node = node->left;
        else if (x > node->data)
            node = node->right;
        else
            return node;
    }
    return NULL;
}

Node *find(Bst *bst, int x){
    Node *temp = _find(bst->root, x);
    if (temp)
        return temp;
    else
        return NULL;
}

void solve_from_bottom(Node* node){
    while(node->parent){
        long long temp = node->dleaf + node->dparent;
        node = node->parent;
        if(node->dleaf > temp)
            node->dleaf = temp;
    }
}

void solve_from_top(Node* node){
    if(node){
        if(node->parent){
            long long temp;
            temp = node->parent->dleaf + node->dparent;
            if(node->dleaf > temp)
                node->dleaf = temp;
        }

        solve_from_top(node->left);
        solve_from_top(node->right);
    }
}

void getleaf(Node* node){
    if(node){
        if(node->left || node->right){
            getleaf(node->left);
            getleaf(node->right);
        } else {
            //leaf node
            node->dleaf=0;
            solve_from_bottom(node);
        }
    }
}

int main(){
    Bst bst;
    bst_init(&bst);
    int n,root;
    scanf("%d%d",&n,&root);
    bst.root = createNode(root,-1);
    n--;
    while (n--)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        bst_insert(&bst, p,q);
    }
    getleaf(bst.root);
    solve_from_top(bst.root);
    scanf("%d",&n);

    // tambahkan array output dan index outputIdx
    int output[n], outputIdx = 0;

    while(n--){
        int searchval;
        scanf("%d",&searchval);
        Node *res = find(&bst,searchval);
        if(res)
            output[outputIdx++] = res->dleaf;
        else
            output[outputIdx++] = 0;
    }

    // cetak semua elemen dalam array output
    for(int i = 0; i < outputIdx; i++) {
        printf("%d ", output[i]);
    }
    return 0;
}


/*
10 6
2 3
7 5
1 1
3 3
10 5
4 1
8 8
5 4
9 7
5
1
2
3
4
5
*/
