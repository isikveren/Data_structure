#pragma once
#ifndef LINKQUEUE_H
#define LINKQUEUE_H

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
}

template<class DataType>
inline LinkQueue<DataType>::~LinkQueue()
{
}

template<class DataType>
inline void LinkQueue<DataType>::EnQueue(DataType x)
{
}

template<class DataType>
inline DataType LinkQueue<DataType>::DeQueue()
{
	return DataType();
}

template<class DataType>
inline DataType LinkQueue<DataType>::GetQueue()
{
	return DataType();
}

#endif