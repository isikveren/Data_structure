#include<iostream>  //单链表
//#include<cstdio>
//#define N 10;
//typedef int ElemType;
using namespace std;

struct Node{
    int data;    
    Node *next;
};  
bool GetNode(Node *s,int i,int *e);
bool GetData(Node *s,int* i,int e);
void CreateList(Node *LinkList,int n);
void ShowList(Node *LinkList);
bool ClearList(Node *LinkList);

int main(){
    bool sign;
    Node *LinkList = new Node();            //给节点分配空间
    LinkList->next = NULL;                  
    int *count = new int();             //给指针分配空间
    CreateList(LinkList,5);
    ShowList(LinkList);
     if(GetNode(LinkList,2,count)){
         cout<<*count<<endl;
     }
     if(GetData(LinkList,count,4)){
         cout<<*count<<endl;
     }
    //cout<<GetElem(LinkList,2,count)<<"\t"<<count<<endl;
    delete count;
    sign = ClearList(LinkList);
    cout<<"sigle : "<<sign<<endl;
    ShowList(LinkList);
    system("pause");
    return 0;
}

bool GetNode(Node *s,int i,int *e)      //找到链表第i个节点，数据存放在*e(头节点不存放数据)
{

    Node *p = s->next;
    int j=1;
    while(p&&j<i){              //5 4 3 2 1 
        p = p->next;
        j++;
    }
    if(!p||j>i) return 0;               //指针为空 或者
    *e = p->data;
    return 1; 
}

bool GetData(Node *s,int* i,int e)      //找到链表值为e的节点
{   
    Node *p = s->next;
    int j;
    for(j = 1;p&&p->data!=e;j++)
    {
        p = p->next;
    }
    *i = j;
    if(!p)  return 0;
    else    return 1;
}

void CreateList(Node *LinkList,int n) //输入一个n个数据的单链表
{
      for(int i = 0;i < n;i++){
        int num;
        Node *p = new Node();
        cin >> num;
        p->data = num;
        p->next = LinkList->next;
        LinkList->next = p;
    }
}

void ShowList(Node *LinkList)  //输出单链表
{
    Node *p = LinkList->next;
    while(p){
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}

bool ClearList(Node *LinkList){   //清空链表

    Node *p,*q;
    p = LinkList ->next;
    while(p){
        q = p->next;
        delete p;
        p = q;
    }
    LinkList ->next  = NULL;
    return 1;
}