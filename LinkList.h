#pragma once
#ifndef LINKLIST
#define LINKLIST

#include<iostream>  //������
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
	cout << "����һ����" << n << "�����ĵ�����" << endl;
	this->next = NULL;
	for (int i = 1; i <= n; i++) {
		int num;
		Node* p = new Node();
		cout << "�������" << i << "������ֵ��" << endl;
		cin >> num;
		p->data = num;
		p->next = this->next;
		this->next = p;
	}
}

Node::~Node()
{

}



bool Node::GetNode(int i, int* e)      //�ҵ������i���ڵ㣬���ݴ����*e(ͷ�ڵ㲻�������)
{

	Node* p = this->next;
	int j = 1;
	while (p && j < i) {              //5 4 3 2 1 
		p = p->next;
		j++;
	}
	if (!p || j > i) return 0;               //ָ��Ϊ�� ����
	*e = p->data;
	return 1;
}

bool Node::GetData(int* i, int e)      //�ҵ�����ֵΪe�Ľڵ�
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


void Node::ShowList()  //���������
{
	Node* p = this->next;
	while (p) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

bool Node::ClearList() {   //�������

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