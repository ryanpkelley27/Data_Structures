#pragma once
#ifdef _DEBUG
	#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#else
	#define DBG_NEW new
#endif

#include "SingleList.h"

//add node to the end
template <typename T>
Single_Node<T>* Single_List<T>::push_back(const T& load) {
	Single_Node<T>* new_node = DBG_NEW Single_Node(load);

	if (count == 0) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		tail = new_node;
	}
	count++;
	return new_node;
}

//remove specified node
template <typename T>
void Single_List<T>::remove(Single_Node<T>* node) {
	Single_Node<T>* previous = find_previous(node);
	Single_Node<T>* next = node->next;

	//change the previous node's next pointer
	if (previous != nullptr) {
		previous->next = next;
	}

	//update head
	if (previous == nullptr) {
		head = next;
	}
	//update tail
	if (next == nullptr) {
		tail = previous;
	}

	delete node;
}

//removes tail node and returns copy of value
template <typename T>
T Single_List<T>::pop() {
	T l = tail->load;
	remove(tail);
	return l;
}

//inserts payload before given node
template <typename T>
Single_Node<T>* Single_List<T>::insert(Single_Node<T>* destination, const T& load) {
	Single_Node<T>* new_node = DBG_NEW Single_Node<T>(load);
	Single_Node<T>* previous = find_previous(destination);

	previous->next = new_node;
	new_node->next = destination;

	return new_node;
}

template <typename T> void Single_List<T>::move(Single_Node<T>* destination, Single_Node<T>* node) {
	Single_Node<T>* prev = find_previous(node);
	Single_Node<T>* destination_prev = find_previous(destination);

	//update tail
	if (node == tail) {
		tail = prev;
	}

	//take node out
	if (prev != nullptr) {
		prev->next = node->next;
	}

	//put node before destination
	if (destination_prev != nullptr) {
		destination_prev->next = node;
	}
	node->next = destination;

	//update head
	if (destination == head) {
		head = node;
	}  
}
template <typename T> void Single_List<T>::swap() {}
template <typename T> void Single_List<T>::reverse() {}

//find previous node
template <typename T>
Single_Node<T>* Single_List<T>::find_previous(Single_Node<T>* node) {
	Single_Node<T>* current = head;
	Single_Node<T>* previous = nullptr;

	//find previous node
	while (current != node && current != nullptr) {
		previous = current;
		current = current->next;
	}

	if (current == nullptr) {//return nullptr if node is not in list
		return nullptr;
	}
	else {//return previous node(will be nullptr if node==head)
		return previous;
	}
}

//find node by value
template <typename T>
Single_Node<T>* Single_List<T>::find(const T& val) {
	Single_Node<T>* current = head;
	while (current != nullptr) {
		if (current->load == val) {
			return current;
		}
		current = current->next;
	}
	return nullptr;//value not in list
}

//empties list
template <typename T>
void Single_List<T>::clear() {
	//free nodes
	Single_Node<T>* current = head;
	Single_Node<T>* next = nullptr;

	//reset vars
	count = 0;
	head = nullptr;
	tail = nullptr;

	while (current != nullptr) {
		next = current->next;
		delete current;
		current = next;
	}
}

//overload << operator for ostreams
template <typename T>
std::ostream& operator<<(std::ostream& out, const Single_List<T>& sl) {
	if (sl.count == 0) {
		out << "Empty" << std::endl;
		return out;
	}
	Single_Node<T>* current = sl.head;
	while (current != nullptr) {
		out << *current << ":";
		if (current->next != nullptr) {
			out << *(current->next);
		}

		out << std::endl;
		current = current->next;
	}

	return out;
}