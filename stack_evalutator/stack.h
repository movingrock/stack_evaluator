#pragma once

#include <cassert>
#include "node.h"

template <class Item>
class stack {
private:
	node<Item>* top_ptr;

public:
	stack();
	stack(const stack<Item>& source); //복사 생성자

	void push(const Item& entry);  //스택 제일 위에 값 집어넣기
	void pop(); //스택 제일 위에 값 빼기
	bool empty() const; // 스택 비우기
	Item top() const; // 스택 제일 위에 값 반환

	void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr); // 스택 복사
	void list_insert(node<Item>* previous_ptr, node<Item>* next_ptr, const Item& entry); // 원하는 위치에 노드 삽입(list_copy를 위한 함수)
	void list_head_insert(node<Item>*& head_ptr, const Item& entry); // 스택 제일 위에 노드 삽입
	void list_head_remove(node<Item>*& head_ptr); // 스택 제일 위 노드 삭제
};