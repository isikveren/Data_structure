#include "LinkList.h"

int main() {
	Node* LinkList = new Node(5);            //给节点分配空间
	LinkList->ShowList();
	int count1,count2,n,m;
	cout << "按位次查找结点：请问需要查找第几个结点？" << endl;
	cin >> n;
	if (LinkList->GetNode(n, &count1)) {
		cout << "第"<<n<<"个结点的数值为：" << count1 << endl;
	}
	else {
		cout << "不存在第"<<n<<"个结点" << endl;
	}
	cout << "按值查找结点：请问需要查找数值为多少的结点？" << endl;
	cin >> m;
	if (LinkList->GetData(&count2, m)) {
		cout << "数值为" << m << "的结点是第" << count2 <<"个。" << endl;
	}


	LinkList->InsertList(3);
	LinkList->ShowList();
	LinkList->ClearList();
	system("pause");
	return 0;
}