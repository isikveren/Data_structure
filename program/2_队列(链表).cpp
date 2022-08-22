#include<iostream>

using namespace std;
typedef int ElemType;

struct Node{
    ElemType data;
    struct Node* next;
};
struct QNode{
    struct Node *rear;
    struct Node *front;
};
typedef struct QNode *Queue;

ElemType DeleteQ(Queue PtrQ);
int main(){



    system("pause");
    return 0;

}


ElemType DeleteQ(Queue PtrQ){
    struct Node *FrontCell;
    ElemType FrontElem;
    if(PtrQ->front == NULL) 
    {
        cout<<"队列空"<<endl;
        return 0;  //空
    }
    FrontCell = PtrQ->front;
    if(PtrQ->front == PtrQ->rear)   
        PtrQ->front = PtrQ->rear = NULL;
    else PtrQ->front = PtrQ->front->next;
    FrontElem = FrontCell->data;
    delete FrontCell;
    return FrontElem;
}