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
	void EnQueue(DataType x);    //入队
	DataType DeQueue();			//出队
	DataType GetQueue();		//获取队头元素
	bool Empty();				//判断队列是否为空

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
void LinkQueue<DataType>::EnQueue(DataType x)
{
	Node<DataType>* s = NULL;
	s = new Node<DataType>;
	s->data = x;
	s->next = NULL;
	rear->next = s;
	rear = s;
	//std::cout << "将" << x << "入队" << std::endl;
}

template<class DataType>
DataType LinkQueue<DataType>::DeQueue()
{
	Node<DataType>* p = NULL;
	DataType x;
	if (this->front == this->rear)
	{
		std::cerr << "队列空" << std::endl;
		return 0;  //空
	}
	p = this->front->next;
	x = p->data;
	front->next = p->next;
	if (p->next == NULL) {
		rear = front;
	}
	delete p;
	return x;
}

template<class DataType>
DataType LinkQueue<DataType>::GetQueue()
{
	if (front != rear) {
		return front->next->data;
	}
}

template<class DataType>
inline bool LinkQueue<DataType>::Empty()
{
	if (front == rear) {
		return 1;
	}
	else {
		return 0;
	}
}

#endif