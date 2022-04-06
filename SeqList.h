#pragma once
#ifndef SEQLIST
#define SEQLIST
#endif // !SEQLIST
#include <iostream>
const int  MaxSize = 20;

class sqList
{
private:
	/* data */
	int data[MaxSize];
	int length;

public:
	sqList(int* arr, int len);
	sqList();
	bool ListInsert(int i, int e);
	void PrintList();
	bool ListDelete(int i, int n);
};

sqList::sqList(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		this->data[i] = arr[i];
	}
	this->length = len;
}
sqList::sqList() {
	this->length = 0;
}

bool sqList::ListInsert(int i, int e)
{
	{

		if (this->length == MaxSize)
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
		std::cout << "�ڵ�" << i << "λǰ���Ԫ�أ���ֵΪ" << e << std:: endl;
		//std::cout << "����" << this->length << std::endl;

		return 1;
	}
}
void sqList::PrintList()
{
	std::cout << "���˳���" << std::endl;
	for (int i = 0; i < this->length; i++)
	{
		if (i == this->length - 1)
			std::cout << this->data[i] << std::endl;
		else
			std::cout << this->data[i] << " ";
	}
}
bool sqList::ListDelete(int i, int n)
{

	if (this->length == 0 || i < 1 || i > this->length)
		return 0;

	if (i < this->length)
	{
		for (int k = i - 1; k + n < this->length; k++)
		{
			this->data[k] = this->data[k + n];
		}
	}
	if (i + n <= this->length) {
		this->length -= n;
	}
	else {
		this->length = i;
	}

	std::cout << "�ӵ�" << i << "Ԫ�ؿ�ʼɾ��" << n << "��Ԫ��" << std::endl;
	//std::cout << "����" << this->length << std::endl;
	return 1;
}
