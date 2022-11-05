#pragma once
#ifndef LINKLIST
#define LINKLIST

#include <iostream> //单链表
using namespace std;

template <class DateType>
struct Node
{
	Node<DateType> *next;
	DateType data;
};

template <class DateType>
class LinkList
{
public:
	LinkList();
	LinkList(DateType *a, int n);
	~LinkList();
	void ShowList();
	void Delete(int i);
	bool InsertNode(int i, DateType x);
	bool SearchNode(int i);

private:
	Node<DateType> *first;
	int length;
};

template <class DateType>
LinkList<DateType>::LinkList()
{
	first = new Node<DateType>;
	first->next = NULL;
}

template <class DateType>
LinkList<DateType>::LinkList(DateType *a, int n) //尾插法
{
	first = new Node<DateType>;
	Node<DateType> *r, *s;
	r = first;
	for (int i = 0; i < n; i++)
	{
		s = new Node<DateType>;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
	length = n;
}

template <class DateType>
LinkList<DateType>::~LinkList()
{
	Node<DateType> *q = NULL;
	while (first)
	{
		q = first;
		first = first->next;
		delete q;
	}
}

template <class DateType>
void LinkList<DateType>::ShowList() //输出单链表
{
	cout << "输出单链表" << endl;
	Node<DateType> *p = first->next;
	while (p)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

template <class DateType>

void LinkList<DateType>::Delete(int i) //删除第i个结点
{

	Node<DateType> *p = first, *q = NULL;
	int count = 0;
	while (p && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p != NULL || p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		delete q;
		length--;
		cout << "删除第" << i << "个结点" << endl;
	}
}

template <class DateType>
bool LinkList<DateType>::InsertNode(int i, DateType x) //在第 i个结点后插入结点
{
	if (i > length)
		return 0;
	Node<DateType> *p = first->next, *q = new Node<DateType>;
	q->data = x;
	int count = 1;
	while (p && count < i)
	{
		p = p->next;
		count++;
	}
	q->next = p->next;
	p->next = q;
	length++;
	cout << "在第" << i << "个结点后插入值为" << x << "的结点" << endl;
	return 1;
}

template <class DateType>
bool LinkList<DateType>::SearchNode(int i) //查找第i个结点
{
	if (i > length)
		return 0;
	Node<DateType> *p = first->next;
	int count = 1;
	while (p && count < i)
	{
		p = p->next;
		count++;
	}
	cout << "查找结点:第" << i << "个结点的值为" << p->data << endl;
	return 1;
}
#endif