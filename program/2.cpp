#include "LinkList.h"

int main() {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	LinkList<int> l(a,9);            //给节点分配空间
	l.ShowList();

	l.Delete(3);
	l.ShowList();

	l.InsertNode(8, 10);
	l.ShowList();

	l.SearchNode(3);
	system("pause");
	return 0;
}