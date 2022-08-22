#include<iostream>
#define MaxSize 10

using namespace std;
typedef int TElemType;

typedef struct TreeNode* BinTree;
typedef struct SNode* Stack;
typedef struct QNode* Queue;
struct TreeNode {
    TElemType data = 0;
    TreeNode* lchild = NULL;
    TreeNode* rchild = NULL;
};
struct SNode {
    BinTree data[MaxSize] = {};
    int top = -1;
};
struct QNode {
    BinTree data[MaxSize] = {};
    int rear  = -1;
    int front = -1;
};
BinTree Pop(Stack PtrS);
int IsEmpty(Stack S);
int IsEmptyQ(Queue Q);
void Push(Stack PtrS, BinTree item);
void AddQ(Queue Q, BinTree item);
BinTree DeleteQ(Queue Q);
void PreOrderTravesal(TreeNode* T);   //先序遍历
void PreOrderTravesal2(TreeNode* BT);   //非递归先序遍历
void InOrderTravesal(TreeNode* T);
void InOrderTravesal2(BinTree BT);
void PostOrderTravesal(TreeNode* T);
int PostOrderGetHeight(BinTree BT);
void LevelOrderTravesal(TreeNode* BT);
void PreOrderPrintLeaves(BinTree BT);  //访问叶子结点

int main() {
    TreeNode* t = new TreeNode();
    TreeNode* t1 = new TreeNode();
    TreeNode* t2 = new TreeNode();
    t->data = 1;
    t1->data = 2;
    t2->data = 3;
    t->lchild = t1;
    t->rchild = t2;
    /*PreOrderTravesal(t);
    InOrderTravesal(t);
    PostOrderTravesal(t);*/
    cout << "中序遍历" << endl;
    InOrderTravesal2(t);
    cout << "先序遍历" << endl;
    PreOrderTravesal2(t);
    cout << "层次遍历" << endl;
    LevelOrderTravesal(t);
    cout << "访问叶子结点" << endl;
    PreOrderPrintLeaves(t);
    cout << "树的高度" << PostOrderGetHeight(t)<<endl;

    system("pause");
    delete t;
    return 0;
}

void PreOrderTravesal(TreeNode* T) {
    if (T) {
        cout << T->data << endl;
        PreOrderTravesal(T->lchild);
        PreOrderTravesal(T->rchild);
    }
}
void PreOrderTravesal2(TreeNode* BT)
{
    BinTree T = BT;
    Stack S = new SNode();
    while (T || !IsEmpty(S)) {
        while (T) {
            Push(S, T);
            cout << T->data << endl;
            T = T->lchild;
        }
        if (!IsEmpty(S)) {
            T = Pop(S);
            T = T->rchild;
        }

    }
}
void InOrderTravesal(TreeNode* T) {
    if (T) {

        InOrderTravesal(T->lchild);
        cout << T->data << endl;
        InOrderTravesal(T->rchild);
    }
}
void PostOrderTravesal(TreeNode* T) {
    if (T) {

        PostOrderTravesal(T->lchild);
        PostOrderTravesal(T->rchild);
        cout << T->data << endl;
    }
}

int PostOrderGetHeight(BinTree BT)
{
    int HL, HR, MaxH;
    if (BT==NULL)   return 0;
    else {
        HL = PostOrderGetHeight(BT->lchild);
        HR = PostOrderGetHeight(BT->rchild);
        MaxH = (HL > HR) ? HL : HR;
        return (MaxH + 1);
    }
    
}

void InOrderTravesal2(BinTree BT) {
    BinTree T = BT;
    Stack S = new SNode();
    while (T || !IsEmpty(S))
    {
        while(T){
            Push(S, T);
            T = T->lchild;
        }
    if (!IsEmpty(S)) {
        T = Pop(S);
        cout << T->data << endl;
        T = T->rchild;
    }
    }

}

void Push(Stack PtrS, BinTree item)
{
    if (PtrS->top == MaxSize-1)
    {
        cout << "栈满" << endl;
        return;
    }
    else {
        PtrS->data[++(PtrS->top)] = item;
       // cout << "yes" << endl;
        return;
    }
}
int IsEmpty(Stack S) {
    if (S->top == -1)    return 1;
    else return 0;
}

int IsEmptyQ(Queue Q)
{
    if (Q->front == Q->rear) return 1;
    else return 0;
}

BinTree Pop(Stack PtrS)
{
    if (PtrS->top == -1)
    {
        cout << "栈空" << endl;
        return 0;
    }
    else    return (PtrS->data[(PtrS->top)--]);

}

void AddQ(Queue Q, BinTree item) {
    if ((Q->rear + 1) % MaxSize == Q->front)
    {
        cout << "队列满" << endl;
        return;
    }
   
    Q->rear = (Q->rear + 1) % MaxSize;
    Q->data[Q->rear] = item;
}

BinTree DeleteQ(Queue Q) {
    if (Q->front != Q->rear) {
        Q->front = (Q->front + 1) % MaxSize;
        return Q->data[Q->front];
    }
}

void LevelOrderTravesal(TreeNode* BT) {
    if (!BT) return;
    BinTree T;
    Queue Q = new QNode();
    AddQ(Q, BT);
    while (!IsEmptyQ(Q)) {
        T = DeleteQ(Q);
        cout << T->data << endl;
        if (T->lchild)   AddQ(Q, T->lchild);
        if (T->rchild)   AddQ(Q, T->rchild);
    }
}

void PreOrderPrintLeaves(BinTree BT)
{  
    if (BT) {
        if (!BT->lchild && !BT->rchild)
            cout << BT->data << endl;
        PreOrderPrintLeaves(BT->lchild);
        PreOrderPrintLeaves(BT->rchild);
            
    }
}
