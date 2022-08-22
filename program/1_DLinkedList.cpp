#include<iostream>  //双链表

using namespace std;
struct DNode{
    int data;
    DNode *piror,*next;
};
bool InitDLinkedList(DNode *L);
int main(){
    DNode *L  = new DNode();
    cout<<InitDLinkedList(L)<<endl;
    system("pause");
    return 0;
}

bool InitDLinkedList(DNode *L){
    //L = new DNode();
    if(L==NULL) return 0;
    L->next = NULL;
    L->piror = NULL;
    return 1;
}