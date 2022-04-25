#pragma once
#ifndef LINKQUEUE_H
#define LINKQUEUE_H
#include <iostream>

template<class DataType>
struct Node {
	DataType data;
	Node<DataType>* next;
};

template<class DataType>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();
	void EnQueue(DataType x);
	DataType DeQueue();
	DataType GetQueue();

private:
	Node<DataType>* front, * rear;
};

template<class DataType>
inline LinkQueue<DataType>::LinkQueue()
{
	Node<DataType>* s = NULL;
	s = new Node<DataType>;
	s->next = NULL;
	front = rear = s;
}

template<class DataType>
inline LinkQueue<DataType>::~LinkQueue()
{
	Node<DataType>* p = NULL;
	while (front) {
		p = front->next;
		delete front;
		front = p;
	}
}

template<class DataType>
inline void LinkQueue<DataType>::EnQueue(DataType x)
{
}

template<class DataType>
DataType LinkQueue<DataType>::DeQueue()
{
	struct Node* FrontCell;
	DataType FrontElem;
	if (this->front == NULL)
	{
		std::cout << "╤сап©у" << std::endl;
		return 0;  //©у
	}
	FrontCell = this->front;
	if (this->front == this->rear)
		this->front = this->rear = NULL;
	else this->front = this->front->next;
	FrontElem = FrontCell->data;
	delete FrontCell;
	return FrontElem;
}

template<class DataType>
inline DataType LinkQueue<DataType>::GetQueue()
{
	return DataType();
}

#endif