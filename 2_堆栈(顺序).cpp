#include <iostream>
using namespace std;
#define MaxSize 10
typedef int ElemType;
typedef struct SNode *Stack;
struct SNode
{
    ElemType data[MaxSize];
    int top;
};
int IsEmpty(Stack S);
void Push(Stack PtrS, ElemType item);
ElemType Pop(Stack PtrS);
int main()
{
    Stack s = new SNode();
    s->top = -1;
    Push(s, 1);
    cout << s->data[s->top] << endl;
    cout << Pop(s) << endl;
    system("pause");
    return 0;
}

void Push(Stack PtrS, ElemType item)
{
    if (PtrS->top == MaxSize - 1)
    {
        cout << "栈满" << endl;
        return;
    }
    else
    {
        PtrS->data[++(PtrS->top)] = item;
        cout << "yes" << endl;
        return;
    }
}

ElemType Pop(Stack PtrS)
{
    if (PtrS->top == -1)
    {
        cout << "栈空" << endl;
        return 0;
    }
    else
        return (PtrS->data[(PtrS->top)--]);
}

int IsEmpty(Stack S)
{
    if (S->top == -1)
        return 1;
    else
        return 0;
}