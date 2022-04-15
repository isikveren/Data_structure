#include "SeqStack.h"

int main() {
	SeqStack<int> s(10);
	s.Push(1);
	s.Push(2);

	int x = 0;

	s.Pop(x);
	cout << x << endl;

	//delete s;
	//system("pause");
	return 0;
}