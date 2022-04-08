#pragma once
#ifndef SQLIST
#define SQLIST
#include <iostream>
const int  MaxSize = 20;

class sqList
{
private:
	/* data */
	int data[MaxSize] = {};
	int length;

public:
	sqList(int* arr, int len);
	sqList();
	bool ListInsert(int i, int e);
	void PrintList();
	bool ListDelete(int i, int n);
};

sqList::sqList(int* arr, int len) {
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

	std::cout << "�ڵ�" << i << "��Ԫ��ǰ���Ԫ�أ���ֵΪ" << e << std::endl;
	if (this->length == MaxSize || i < 1 || i > this->length)
	{
		std::cout << "�������λ�÷Ƿ�����" << std::endl;
		return 0;
	}

	for (int k = this->length - 1; k >= i - 1; k--)
		this->data[k + 1] = this->data[k];

	this->data[i - 1] = e;
	this->length++;

	//std::cout << "����" << this->length << std::endl;

	return 1;

}
void sqList::PrintList()
{
	std::cout << "���˳���" << std::endl;
	for (int i = 0; i < this->length; i++)
	{
		std::cout << this->data[i] << " ";
	}
	std::cout << std::endl;
}
bool sqList::ListDelete(int i, int n)
{
	std::cout << "�ӵ�" << i << "��Ԫ�ؿ�ʼɾ��" << n << "��Ԫ��" << std::endl;
	if (this->length == 0 || i < 1 || i > this->length || n > this->length - i + 1)
	{
		std::cout << "ɾ������λ�÷Ƿ�����" << std::endl;
		return 0;
	}

	for (int k = i - 1; k + n < this->length; k++)
	{
		this->data[k] = this->data[k + n];
	}

	this->length -= n;
	//std::cout << "����" << this->length << std::endl;
	return 1;
}
#endif