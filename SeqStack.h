#pragma once
#ifndef SEQSTACK_H
#define SEQSTACK_H

#include <iostream>
using namespace std;

template <class DataType>
class SeqStack
{
private:
	DataType* elements;
	int top;
	int maxSize;
	void overflowProcess();
public:
	SeqStack(int sz);
	~SeqStack() { delete[]elements; };

	void Push(DataType x);
	bool Pop(DataType& x);
	bool getTop(DataType* x);
	bool IsEmpty() const { return top == -1; };
	bool IsFull() const { return top == maxSize - 1; }
};

#endif // !STACK_H

template<class DataType>
void SeqStack<DataType>::overflowProcess()
{
	cout << "overflowProcess" << endl;
}

template<class DataType>
SeqStack<DataType>::SeqStack(int sz)
{
	this->top = -1;
	this->maxSize = sz;
	this->elements = new DataType(this->maxSize);
	if (this->elements == NULL) {
		cerr << "´æ´¢·ÖÅä´íÎó£¡" << endl;
		exit(1);
	}
}

template<class DataType>
void SeqStack<DataType>::Push(DataType x)
{
	if (this->IsFull()) {
		this->overflowProcess();
	}
	else {
		this->elements[++(this->top)] = x;
	}
}

template<class DataType>
bool SeqStack<DataType>::Pop(DataType& x)
{
	if (this->IsEmpty()) {
		this->overflowProcess();
		return false;
	}
	else {
		x = this->elements[(this->top)--];
		return true;
	}

}

template<class DataType>
bool SeqStack<DataType>::getTop(DataType* x)
{
	if (this->IsEmpty()) {
		return false;
	}
	else {
		*x = this->elements[this->top];
		return true;
	}

}
