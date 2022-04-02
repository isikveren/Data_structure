#include<iostream>
#define MaxSize 10
using namespace std;
typedef int ElemType;
typedef struct TreeNode* BinTree;
struct TreeNode {
    ElemType data;
    TreeNode* left ;
    TreeNode* right ;
};

BinTree Insert(ElemType x, BinTree BST);
void PreOrderTravesal(BinTree T);
int main() {
    BinTree BST = new TreeNode();
    BST->data = 5;
    for(int i = -5;i<10;i++) {
        BST = Insert(i, BST);
    }
    for (int i = 10; i < 15; i++) {
        BST = Insert(i, BST);
    }
   
    PreOrderTravesal(BST);
    return 0;
}
BinTree Insert(ElemType x, BinTree BST) {
    if (!BST) {
        BST = new TreeNode();
        BST->data = x;
        BST->left = NULL;
        BST->right = NULL;
    }
    else {
        if (x < BST->data) {
            BST->left = Insert(x, BST->left);
        }
        else if (x > BST->data) {
            BST->right = Insert(x, BST->right);
        }
    }
    return BST;
}

void PreOrderTravesal(BinTree T)
{   
    if (T) {
        cout << T->data << endl;
        PreOrderTravesal(T->left);
        
        PreOrderTravesal(T->right);
    }
}
