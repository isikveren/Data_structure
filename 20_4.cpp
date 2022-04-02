#include<iostream>
using namespace std;
struct lab{
    int val = 0;
    lab* next = NULL;
};
void shurulist(lab *a);
lab* fanzhuanlist(lab *a);
void shuchulist(lab *a);
int main(){
    lab* x = new lab();
    cout<<"分别从大到小输入第1个链表的数值，输入0结束："<<endl;
    shurulist(x);
    //lab* y = new lab();
    //cout<<"分别从大到小输入第2个链表的数值，输入0结束："<<endl;
    //shurulist(y);
    //shuchulist(x);
    lab* test = x;
    //test = fanzhuanlist(x);
    shuchulist(test);
    system("pause");
    return 0;
}

void shurulist(lab *a)
{
    int i;
    while(1){
        cin >>i;
        if(i==0)    break;
        lab* p = new lab();
        p->val = i;
        p->next = a->next;
        a->next = p;
    }
}

lab* fanzhuanlist(lab *a){
    lab* b = new lab();
    lab* p = a->next;
    while(p!=NULL){
        lab*q = new lab();
        q->val = p->val;
        q->next = b->next;
        b->next = q;
        q = q->next;
    }
    shuchulist(b);
    return b;
}
void shuchulist(lab *a){
    lab* p = a;
    while (1)
	{
			
			p = p->next;
            if(p==NULL)  
                {cout <<"NULL"<<endl;
                break;
                }
            cout << (p->val) <<"->";
	}
    delete p;
}