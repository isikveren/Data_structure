#include "LinkList.h"

int main() {
	Node* LinkList = new Node(5);            //���ڵ����ռ�
	LinkList->ShowList();
	int count1,count2,n,m;
	cout << "��λ�β��ҽ�㣺������Ҫ���ҵڼ�����㣿" << endl;
	cin >> n;
	if (LinkList->GetNode(n, &count1)) {
		cout << "��"<<n<<"��������ֵΪ��" << count1 << endl;
	}
	else {
		cout << "�����ڵ�"<<n<<"�����" << endl;
	}
	cout << "��ֵ���ҽ�㣺������Ҫ������ֵΪ���ٵĽ�㣿" << endl;
	cin >> m;
	if (LinkList->GetData(&count2, m)) {
		cout << "��ֵΪ" << m << "�Ľ���ǵ�" << count2 <<"����" << endl;
	}


	LinkList->InsertList(3);
	LinkList->ShowList();
	LinkList->ClearList();
	system("pause");
	return 0;
}