#include <iostream>
#include "SeqList.h"
using namespace std;


int main()
{
	int a[] = {1,2,3,4,5};

	sqList* l = new sqList(a, 5);
	l->PrintList();
	l->ListInsert(1, 1);
	l->PrintList();
	l->ListDelete(4, 5);
	l->PrintList();

	delete l;
	system("pause");
	return 0;
}