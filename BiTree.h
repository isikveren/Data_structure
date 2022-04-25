# ifndef BiTree
# define BiTree_H   

# include<iostream>
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

    void PreOrderh() { PreOrder(this->root); }        //前序遍历
    void InOrderh() { InOrder(this->root); }            //中序遍历
    void PostOrderh() { PostOrder(this->root); }        //后序遍历
    void LevelOrderh() { LevelOrder(this->root); };
private:
    BiNode* root;                              //指向根节点的头指针
    BiNode* Creat(BiNode* bt);       //构造函数调用
    void Release(BiNode* bt);       //析构函数调用
    void PreOrder(BiNode* bt);        //前序遍历调用
    void InOrder(BiNode* bt);            //中序遍历调用:Creat(BiNode* bt)
    void PostOrder(BiNode* bt);         //后序遍历

    void LevelOrder(BiNode* BT);
    void PreOrderPrintLeaves(BiNode* BT);  //访问叶子结点
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
}


#endif