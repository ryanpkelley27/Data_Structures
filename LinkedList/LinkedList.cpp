#pragma once
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#else
#define DBG_NEW new
#endif

#include "LinkedList.h"

//appends a new node to the end
template <typename T>
std::shared_ptr<List_Node<T>> Linked_List<T>::push_back(const T& load) {
	std::shared_ptr<List_Node<T>> new_node = std::make_shared<List_Node<T>>(load);
	 
	if (count == 0) {
		head = new_node;
	}
	else {
		tail->next = new_node;
		new_node->prev = tail;
	} 
	count++;
	tail = new_node;
	return new_node;
}

//removes specified node
template <typename T>
void Linked_List<T>::remove(std::shared_ptr<List_Node<T>> node) {
	std::shared_ptr<List_Node<T>> p = node->prev;
	std::shared_ptr<List_Node<T>> n = node->next;

	if (p != nullptr) {
		p->next = n;
	}
	if (n != nullptr) {
		n->prev = p;
	}

	if (node == head) {
		head = n;
	}
	if (node == tail) {
		tail = p;
	}
	count--;
}

//removes tail node and returns value
template <typename T>
T Linked_List<T>::pop() {
	T l = tail->load;
	remove(tail);
	count--;
	return l;
}

//inserts payload before given node
template <typename T>
std::shared_ptr<List_Node<T>> Linked_List<T>::insert(std::shared_ptr<List_Node<T>> destination, const T& load) {
	std::shared_ptr<List_Node<T>> new_node = std::make_shared<List_Node<T>>(load);
	if (destination->prev != nullptr) {
		(destination->prev)->next = new_node;
	}
	new_node->prev = destination->prev;
	destination->prev = new_node;
	new_node->next = destination;

	if (destination == head) {
		head = new_node;
	}

	count++;
	return new_node;
}

//moves node to before destination
template <typename T>
void Linked_List<T>::move(std::shared_ptr<List_Node<T>> destination, std::shared_ptr<List_Node<T>> node) {
	//update tail
	if (node == tail) {
		tail = node->prev;
	}

	//take node out
	if (node->prev != nullptr) {
		node->prev->next = node->next;
	}
	if (node->next != nullptr) {
		node->next->prev = node->prev;
	}

	//put node before destination
	if (destination->prev != nullptr) {
		destination->prev->next = node;
	}
	node->prev = destination->prev;
	destination->prev = node;
	node->next = destination;

	//update head
	if (destination == head) {
		head = node;
	}
}

//swaps the elements of two lists without moving elements
template <typename T>
void Linked_List<T>::swap(Linked_List<T>& other) {
	//store temp head, tail, count
	std::shared_ptr<List_Node<T>> temp_head = this->head;
	std::shared_ptr<List_Node<T>> temp_tail = this->tail;
	int temp_count = this->count;

	//update this
	this->head = other.head;
	this->tail = other.tail;
	this->count = other.count;

	//update other
	other.head = temp_head;
	other.tail = temp_tail;
	other.count = temp_count;
}

//reverses list
template <typename T>
void Linked_List<T>::reverse() {
	//nothing to reverse
	if (count == 0) {
		return;
	}

	//iteraste and switch next and prev
	auto current = head;
	auto temp = current->next;

	while (current != nullptr) {
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;

		//increment current
		current = current->prev;
	}

	//update head and tail
	temp = head;
	head = tail;
	tail = temp;
}

//find based on value - return pointer to node
template <typename T>
std::shared_ptr<List_Node<T>> Linked_List<T>::find(T val) {
	auto current = head;
	while (current != nullptr) {
		if (current->load == val) {
			return current;
		}
		current = current->next;
	}

	return nullptr;
}

//overload << operator for ostreams
template <typename T>
std::ostream& operator<<(std::ostream& out, const Linked_List<T>& ll) {
	if (ll.count == 0) {
		out << "Empty" << std::endl;
		return out;
	}
	std::shared_ptr<List_Node<T>> current = ll.head;
	while (current != nullptr) {
		if (current->prev != nullptr) {
			out << current->prev;
		}
		else {
			out << " ";
		}
		out << ":" << current << ":";
		if (current->next != nullptr) {
			out << current->next;
		}

		out << std::endl;
		current = current->next;
	}

	return out;
}