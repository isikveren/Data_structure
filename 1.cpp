#include <iostream>
#define MAXSIZE 20
using namespace std;
class sqList
{
private:
	/* data */
	int data[MAXSIZE] = {};
	int length = 0;

public:

	bool ListInsert(int i, int e)
	{
		if (this->length == MAXSIZE)
			return 0;
		if (i < 1 || i > this->length + 1)
			return 0;
		if (i <= this->length)
		{
			for (int k = this->length - 1; k >= i - 1; k--)
				this->data[k + 1] = this->data[k];
		}
		this->data[i - 1] = e;
		this->length++;

		return 1;
	}
	bool PrintList()
	{
		cout << "输出线性表：" << endl;
		for (int i = 0; i < this->length; i++)
		{
			if (i == this->length - 1)
				cout << this->data[i] << endl;
			else
				cout << this->data[i] << " ";
		}
		return 0;
	}
};
int main()
{
	sqList* l = new sqList();
	for (int i = 0; i < 10; i++) {
		l->ListInsert(i, i);
	}
	l->PrintList();
	system("pause");
	return 0;
}