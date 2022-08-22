#include<iostream>

using namespace std;
typedef int ElemType;
typedef struct SNode* Stack;
struct SNode {
    ElemType Data;
    SNode* next=NULL;
};
Stack CreateStack();
int IsEmpty(Stack S);
void Push(ElemType item, Stack S);
ElemType Pop(Stack S);
int main() {
    Stack S = CreateStack();
    Push(2, S);
    cout << Pop(S)<<endl;
    system("pause");
    return 0;
}


Stack CreateStack() {

    Stack S = new SNode();
    S->next = NULL;
    return S;
}

int IsEmpty(Stack S) {
    return (S->next == NULL);
}

void Push(ElemType item, Stack S) {
    SNode* TmpCell = new SNode();
    TmpCell->Data = item;
    TmpCell->next = S->next;
    S->next = TmpCell;
}

ElemType Pop(Stack S) {

    SNode* FirstCell;
    ElemType TopElem;
    if (IsEmpty(S)) {
        cout << "栈空" << endl;
        return 0;  //空
    }
    else
    {
        FirstCell = S->next;
        S->next = FirstCell->next;
        TopElem = FirstCell->Data;
        delete FirstCell;
        return TopElem;
    }

}