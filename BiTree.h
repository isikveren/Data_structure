# ifndef BiTree_H
# define BiTree_H   

# include<iostream>
using namespace std;
#include <cstdlib>	

// �����������ģ��
struct BiNode
{
    char data;		// ���ݳ�Ա:
    BiNode* lchild, * rchild;	// ��\�Һ���ָ��;
};


class BiTree
{
public:
    BiTree() { root = Creat(root); }		// ���캯��	


    ~BiTree() { Release(root); }

    void PreOrderh() { PreOrder(root); }        //ǰ�����
    void InOrderh() { InOrder(root); }            //�������
    void PostOrderh() { PostOrder(root); }        //�������
private:
    BiNode* root;                              //ָ����ڵ��ͷָ��
    BiNode* Creat(BiNode* bt);       //���캯������
    void Release(BiNode* bt);       //������������
    void PreOrder(BiNode* bt);        //ǰ���������
    void InOrder(BiNode* bt);            //�����������
    void PostOrder(BiNode* bt);       //�����������
};



BiNode* BiTree::Creat(BiNode* bt)
{
    char ch;
    cout << "������������" << endl;
    cin >> ch;
    if (ch == '#') return NULL;
    else {
        bt = new BiNode;                     //����һ�����
        bt->data = ch;  //
        bt->lchild = Creat(bt->lchild);  //�ݹ齨��������
        bt->rchild = Creat(bt->rchild); //�ݹ齨��������

    }
    return bt;
}


void BiTree::Release(BiNode* bt)
{
    if (bt != NULL) {
        Release(bt->lchild);   //�ͷ�������
        Release(bt->rchild);  //�ͷ�������
        delete bt;
    }
}


void BiTree::PreOrder(BiNode* bt)
{
    if (bt == NULL) return;   //�ݹ���ý�������
    else {
        cout << bt->data << " ";  //���ʸ�����������
        PreOrder(bt->lchild); //ǰ�����bt��������
        PreOrder(bt->rchild); //ǰ�����bt��������
    }
}



void BiTree::InOrder(BiNode* bt)
{
    if (bt == NULL) return;   //�ݹ���ý�������
    else {
        InOrder(bt->lchild); //�������bt��������
        cout << bt->data << " ";  //���ʸ�����������
        InOrder(bt->rchild); //�������bt��������
    }
}



void BiTree::PostOrder(BiNode* bt)
{
    if (bt == NULL) return;   //�ݹ���ý�������
    else {
        PostOrder(bt->lchild); //ǰ�����bt��������
        PostOrder(bt->rchild); //ǰ�����bt��������
        cout << bt->data << " "; //���ʸ�����������
    }
}


# endif