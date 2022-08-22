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
	void EnQueue(DataType x);    //���
	DataType DeQueue();			//����
	DataType GetQueue();		//��ȡ��ͷԪ��
	bool Empty();				//�ж϶����Ƿ�Ϊ��

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
	//std::cout << "��" << x << "���" << std::endl;
}

template<class DataType>
DataType LinkQueue<DataType>::DeQueue()
{
	Node<DataType>* p = NULL;
	DataType x;
	if (this->front == this->rear)
	{
		std::cerr << "���п�" << std::endl;
		return 0;  //��
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