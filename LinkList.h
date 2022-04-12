#pragma once
#ifndef LINKLIST
#define LINKLIST

#include<iostream>  //单链表
//#include<cstdio>
//#define N 10;
//typedef int ElemType;
using namespace std;

class Node
{
public:
	Node();
	Node(int n);
	~Node();
	bool GetNode(int i, int* e);
	bool GetData(int* i, int e);
	void ShowList();
	bool ClearList();
	void InsertList(int e);

private:
	Node* next;
	int data;

};

Node::Node()
{
	this->next = NULL;
}
Node::Node(int n) {
	cout << "建立一个有" << n << "个结点的单链表：" << endl;
	this->next = NULL;
	for (int i = 1; i <= n; i++) {
		int num;
		Node* p = new Node();
		cout << "请输入第" << i << "个结点的值：" << endl;
		cin >> num;
		p->data = num;
		p->next = this->next;
		this->next = p;
	}
}

Node::~Node()
{

}



bool Node::GetNode(int i, int* e)      //找到链表第i个节点，数据存放在*e(头节点不存放数据)
{

	Node* p = this->next;
	int j = 1;
	while (p && j < i) {              //5 4 3 2 1 
		p = p->next;
		j++;
	}
	if (!p || j > i) return 0;               //指针为空 或者
	*e = p->data;
	return 1;
}

bool Node::GetData(int* i, int e)      //找到链表值为e的节点
{
	Node* p = this->next;
	int j;
	for (j = 1; p && p->data != e; j++)
	{
		p = p->next;
	}
	*i = j;
	if (!p)  return 0;
	else    return 1;
}


void Node::ShowList()  //输出单链表
{
	Node* p = this->next;
	while (p) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

bool Node::ClearList() {   //清空链表

	Node* p, * q;
	p = this->next;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
	this->next = NULL;
	return 1;
}

void Node::InsertList(int e) {
	Node* p = new Node();
	p->data = e;
	p->next = this->next;
	this->next = p;
}
#endif