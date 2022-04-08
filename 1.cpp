#include "SqList.h"

int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9 };

	sqList* l = new sqList(a, 9);
	l->PrintList();
	l->ListInsert(1, 0);
	l->PrintList();
	l->ListInsert(11, 0);
	l->PrintList();
	l->ListDelete(4, 3);
	l->PrintList();
	l->ListDelete(4, 10);
	l->PrintList();


	system("pause");
	return 0;
}