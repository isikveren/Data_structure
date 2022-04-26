# ifndef BiTree
# define BiTree_H   

# include<iostream>
#include "LinkQueue.h"
#include "SeqStack.h"
using namespace std;
#include <cstdlib>	

// 二叉树结点类模板
struct BiNode
{
	char data;		// 数据成员:
	BiNode* lchild, * rchild;	// 左\右孩子指针;
};

class BiTree
{
public:
	BiTree() { root = Creat(this->root); }		// 构造函数	


	~BiTree() { Release(this->root); }

	void PreOrderh() { PreOrder(this->root); cout << endl; }        //前序遍历
	void InOrderh() { InOrder(this->root);  cout << endl; }            //中序遍历
	void PostOrderh() { PostOrder(this->root);  cout << endl; }        //后序遍历
	void LevelOrderh() { LevelOrder(this->root);  cout << endl; };
	void GetTreeLeavesNum() { int x = 0; PreOrderGetLeaves(this->root, &x); cout << "叶子结点个数：" << x << endl; }
	void GetTreeHeight() { cout << "树的高度：" << PostOrderGetHeight(this->root) << endl; };
private:
	BiNode* root;                              //指向根节点的头指针
	BiNode* Creat(BiNode* bt);       //构造函数调用
	void Release(BiNode* bt);       //析构函数调用
	void PreOrder(BiNode* bt);        //前序遍历调用
	void InOrder(BiNode* bt);            //中序遍历调用:Creat(BiNode* bt)
	void PostOrder(BiNode* bt);         //后序遍历

	void LevelOrder(BiNode* BT);
	void PreOrderGetLeaves(BiNode* BT, int* x);  //访问叶子结点
	int PostOrderGetHeight(BiNode* BT); //后序获取二叉树的深度
};

BiNode* BiTree::Creat(BiNode* bt)
{
	char ch;
	cout << "请输入结点数据" << endl;
	cin >> ch;
	if (ch == '#') return NULL;
	else {
		bt = new BiNode;                     //生成一个结点
		bt->data = ch;  //
		bt->lchild = Creat(bt->lchild);  //递归建立左子树
		bt->rchild = Creat(bt->rchild); //递归建立右子树

	}
	return bt;
}

void BiTree::Release(BiNode* bt)
{
	if (bt != NULL) {
		Release(bt->lchild);   //释放左子树
		Release(bt->rchild);  //释放右子树
		delete bt;
	}
}


void BiTree::PreOrder(BiNode* bt)
{
	if (bt == NULL) return;   //递归调用结束条件
	else {
		cout << bt->data << " ";  //访问根结点的数据域
		PreOrder(bt->lchild); //前序遍历bt的左子树
		PreOrder(bt->rchild); //前序遍历bt的右子树
	}
}



void BiTree::InOrder(BiNode* bt)
{
	if (bt == NULL) return;   //递归调用结束条件
	else {
		InOrder(bt->lchild); //中序遍历bt的左子树
		cout << bt->data << " ";  //访问根结点的数据域
		InOrder(bt->rchild); //中序遍历bt的右子树
	}
}



void BiTree::PostOrder(BiNode* bt)
{
	if (bt == NULL) return;   //递归调用结束条件
	else {
		PostOrder(bt->lchild); //前序遍历bt的左子树
		PostOrder(bt->rchild); //前序遍历bt的右子树
		cout << bt->data << " "; //访问根结点的数据域
	}
}

void BiTree::LevelOrder(BiNode* BT)
{
	if (!BT) return;
	BiNode* T = new BiNode();
	LinkQueue<BiNode*>* Q = new LinkQueue<BiNode*>;
	Q->EnQueue(BT);
	while (!Q->Empty()) {
		T = Q->DeQueue();
		cout << T->data << " ";
		if (T->lchild)   Q->EnQueue(T->lchild);
		if (T->rchild)   Q->EnQueue(T->rchild);
	}
}

inline void BiTree::PreOrderGetLeaves(BiNode* BT, int* x)
{
	if (BT) {
		if (!BT->lchild && !BT->rchild)
			(*x)++;
		PreOrderGetLeaves(BT->lchild, x);
		PreOrderGetLeaves(BT->rchild, x);

	}
}

inline int BiTree::PostOrderGetHeight(BiNode* BT)
{
	int HL, HR, MaxH;
	if (BT == NULL)   return 0;
	else {
		HL = PostOrderGetHeight(BT->lchild);
		HR = PostOrderGetHeight(BT->rchild);
		MaxH = (HL > HR) ? HL : HR;
		return (MaxH + 1);
	}
}


#endif