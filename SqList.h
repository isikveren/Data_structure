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

	std::cout << "在第" << i << "个元素前添加元素，数值为" << e << std::endl;
	if (this->length == MaxSize || i < 1 || i > this->length)
	{
		std::cout << "插入操作位置非法！！" << std::endl;
		return 0;
	}

	for (int k = this->length - 1; k >= i - 1; k--)
		this->data[k + 1] = this->data[k];

	this->data[i - 1] = e;
	this->length++;

	//std::cout << "长度" << this->length << std::endl;

	return 1;

}
void sqList::PrintList()
{
	std::cout << "输出顺序表：" << std::endl;
	for (int i = 0; i < this->length; i++)
	{
		std::cout << this->data[i] << " ";
	}
	std::cout << std::endl;
}
bool sqList::ListDelete(int i, int n)
{
	std::cout << "从第" << i << "个元素开始删除" << n << "个元素" << std::endl;
	if (this->length == 0 || i < 1 || i > this->length || n > this->length - i + 1)
	{
		std::cout << "删除操作位置非法！！" << std::endl;
		return 0;
	}

	for (int k = i - 1; k + n < this->length; k++)
	{
		this->data[k] = this->data[k + n];
	}

	this->length -= n;
	//std::cout << "长度" << this->length << std::endl;
	return 1;
}
#endif