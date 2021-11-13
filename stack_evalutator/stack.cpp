#include "stack.h"

template <class Item>
stack<Item>::stack() {

}

template <class Item>
stack<Item>::stack(const stack<Item>& source) {
	node<Item>* tail_ptr;

	list_copy(source.top_ptr, top_ptr, tail_ptr);
}

template <class Item>
void stack<Item>::push(const Item& entry) {
	list_head_insert(top_ptr, entry);
}

template <class Item>
void stack<Item>::pop() { 
	assert(!empty());

	list_head_remove(top_ptr);
}

template <class Item>
bool stack<Item>::empty() const {
	return top_ptr == NULL;
}

template <class Item>
Item stack<Item>::top() const {
	assert(!empty());

	return top_ptr->data();
}

template <class Item>
void stack<Item>::list_copy(const node<Item>* source_ptr, node<Item>*& top_ptr, node<Item>*& tail_ptr) {
	top_ptr = NULL;
	tail_ptr = NULL;
	if (source_ptr == NULL)
		return;

	list_head_insert(top_ptr, source_ptr->data());
	source_ptr = source_ptr->link_f();
	while (source_ptr != NULL) {
		list_insert(tail_ptr, NULL, source_ptr->data());
		tail_ptr = tail_ptr->link_f();
		source_ptr = source_ptr->link_f();
	}
}

template <class Item>
void stack<Item>::list_insert(node<Item>* previous_ptr, node<Item>* next_ptr, const Item& entry) {
	node<Item>* insert_ptr;
	insert_ptr = new node;
	insert_ptr->set_data(entry);
	insert_ptr->set_flink(previous_ptr->link_f());
	insert_ptr->set_rlink(next_ptr->link_r());
	previous_ptr->set_flink(insert_ptr);
	next_ptr->set_rlink(insert_ptr);
}

template <class Item>
void stack<Item>::list_head_insert(node<Item>*& top_ptr, const Item& entry) {
	top_ptr = new node<Item>(entry, top_ptr, NULL);
}

template <class Item>
void stack<Item>::list_head_remove(node<Item>*& top_ptr) {
	node<Item>* remove_ptr;
	remove_ptr = top_ptr;
	top_ptr = top_ptr->link_f();
	delete remove_ptr;
}