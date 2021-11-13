#pragma once

#include <cassert>
#include "node.h"

template <class Item>
class stack {
private:
	node<Item>* top_ptr;

public:
	stack();
	stack(const stack<Item>& source); //���� ������

	void push(const Item& entry);  //���� ���� ���� �� ����ֱ�
	void pop(); //���� ���� ���� �� ����
	bool empty() const; // ���� ����
	Item top() const; // ���� ���� ���� �� ��ȯ

	void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr); // ���� ����
	void list_insert(node<Item>* previous_ptr, node<Item>* next_ptr, const Item& entry); // ���ϴ� ��ġ�� ��� ����(list_copy�� ���� �Լ�)
	void list_head_insert(node<Item>*& head_ptr, const Item& entry); // ���� ���� ���� ��� ����
	void list_head_remove(node<Item>*& head_ptr); // ���� ���� �� ��� ����
};