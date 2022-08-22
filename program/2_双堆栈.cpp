#include<iostream>

using namespace std;
#define Maxsize 10
typedef int ElemType;

struct DStack{
    ElemType Data[Maxsize];
    int Top1;
    int Top2;
};
void Push(DStack* PtrS,int item,int Tag);
ElemType Pop(DStack *PtrS,int tag);
int main(){
    DStack* s = new DStack();
    s->Top1 = -1;
    s->Top2 = Maxsize; 
    Push(s,2,1);
    cout<<Pop(s,1);
    system("pause");
    return 0;
}

void Push(DStack* PtrS,int item,int Tag){
    if(PtrS->Top2 - PtrS->Top1 == 1)
    {
        cout<<"栈空"<<endl;
        return;
    }
    if(Tag == 1)
        PtrS->Data[++PtrS->Top1] = item;
    else
    {
        PtrS->Data[--PtrS->Top2] = item;
    } 
    

}

ElemType Pop(DStack *PtrS,int tag)
{
    if(tag == 1){
        if(PtrS->Top1 == -1){
            cout<<"栈1空"<<endl;
            return 0;  //空值
        }else
        {
            return PtrS->Data[(PtrS->Top1)--];
        }
    }
    else
    {
        if(tag==Maxsize){
            cout<<"栈2空"<<endl;
            return 0;
        }
        else
        {
            return PtrS->Data[(PtrS->Top2)++];
        }
        
    }
    
}
