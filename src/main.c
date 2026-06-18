#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void arvoreInorder(struct TreeNode* root, struct TreeNode** anterior, struct TreeNode** primeiro, struct TreeNode** segundo) {
    if(root != NULL) {
        arvoreInorder(root->left, anterior, primeiro, segundo);
        if(*anterior != NULL && (*anterior)->val > root->val) {
            if(*primeiro == NULL) {
                *primeiro = *anterior;
            }
            *segundo = root;
        }
        *anterior = root;
        arvoreInorder(root->right, anterior, primeiro, segundo);
    }
}

void recoverTree(struct TreeNode* root) {

    struct TreeNode *anterior = NULL;
    struct TreeNode *primeiro = NULL;
    struct TreeNode *segundo = NULL;

    arvoreInorder(root, &anterior, &primeiro, &segundo);

    int aux = primeiro->val;
    primeiro->val = segundo->val;
    segundo->val = aux;
}

struct TreeNode* Inserir(struct TreeNode* root, int val, int dir) {
    if(root==NULL) {
        struct TreeNode* aux = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        aux->val = val;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else {
        if(dir == 0) {
            root->left = Inserir(root->left, val, dir);
        } else {
            root->right = Inserir(root->right, val, dir);
        }
        return root;
    }
}

void Imprimir(struct TreeNode* root) {
    if(root!=NULL) {
        Imprimir(root->left);
        printf("%d ", root->val);
        Imprimir(root->right);
    }
}

int main() {
    struct TreeNode* arv = NULL;

    arv = Inserir(arv, 10, 0);
    arv = Inserir(arv, 15, 0);
    arv = Inserir(arv, 5, 1);
    arv = Inserir(arv, 16, 1);
    arv = Inserir(arv, 17, 1);
    arv = Inserir(arv,  4, 0);
    arv = Inserir(arv,  3, 0);
   
    

    printf("Inorder antes de arrumar a BST: ");
    Imprimir(arv);
    recoverTree(arv);
    printf("\nInorder depois de arrumar a BST: ");
    Imprimir(arv);

    return 0;
}
