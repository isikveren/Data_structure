#include "SeqStack.h"

int main() {
	SeqStack<int>* s = new SeqStack<int>(10);
	int i = 0;
	while (!s->IsFull()) {
		s->Push(++i);
	}
	

	int x = 0;
	s->Pop(x);
	cout << "��ջ��������x�У�x = "<<x << endl;
	s->getTop(x);
	cout << "��ȡջ��Ԫ�أ�" << x << endl;

	delete s;
	//system("pause");
	return 0;
}