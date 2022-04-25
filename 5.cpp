#include "BiTree.h"

int main() {
	BiTree* t = new BiTree();

	cout << "先序遍历：" << endl;
	t->PreOrderh();
	cout << "中序遍历：" << endl;
	t->InOrderh();
	cout << "后序遍历：" << endl;
	t->PostOrderh();


	
	return 0;
}