#include<iostream>

using namespace std;

struct DNode{
    int data;
    DNode *next;
};
struct DDNode{
    int data;
    DDNode *next;
    DDNode *prior;  
};

int main(){
    DNode *l = new DNode();
    l->next = l;
    DDNode *d = new DDNode();
    d->next = d;
    d->prior = d;
    system("pause");
    return 0;
}