#include<iostream>
#define MaxSize 10
using namespace std;
typedef int ElemType;
typedef struct QNode* Queue;
struct QNode{
    ElemType Data[MaxSize];
    int rear;
    int front;
};
void AddQ(Queue Q,int item);

int main(){

    system("pause");
    return 0;
}

void AddQ(Queue Q,int item){
    if((Q->rear+1)%MaxSize == Q->front)
    {
        cout<<"队列满"<<endl;
        return;
    }
    Q->rear = (Q->rear+1)%MaxSize;
    Q->Data[Q->rear] = item;
}