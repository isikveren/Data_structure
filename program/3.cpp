#include "SeqStack.h"

int main() {
	SeqStack<int>* s = new SeqStack<int>(10);
	int i = 0;
	while (!s->IsFull()) {
		s->Push(++i);
	}
	

	int x = 0;
	s->Pop(x);
	cout << "出栈结果存放在x中，x = "<<x << endl;
	s->getTop(x);
	cout << "获取栈顶元素：" << x << endl;

	delete s;
	//system("pause");
	return 0;
}