#include "LinkQueue.h"

int main() {

	LinkQueue<int>* l = new LinkQueue<int>;
	l->EnQueue(1);
	l->EnQueue(2);

	std::cout << "��ȡ��ͷԪ��" << std::endl;
	std::cout<<l->GetQueue()<<std::endl;

	std::cout << "����" << std::endl;
	std::cout << l->DeQueue() << std::endl;

	std::cout << "��ȡ��ͷԪ��" << std::endl;
	std::cout << l->GetQueue() << std::endl;
	return 0;
}