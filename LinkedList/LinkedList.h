#pragma once
#include <memory>
#include <iostream>
#include <string>

template <typename T2> class Linked_List;

template <typename T>
class List_Node {
	friend class Linked_List<T>;
public:
	T load;
	//doubly linked
	std::shared_ptr<List_Node<T>> next;
	std::shared_ptr<List_Node<T>> prev;
	List_Node(T load, std::shared_ptr<List_Node<T>> next = nullptr, std::shared_ptr<List_Node<T>> prev = nullptr) : load(load), next(next), prev(prev) {}
};

template <typename T2>
class Linked_List {
private:
	std::shared_ptr<List_Node<T2>> head = nullptr;
	std::shared_ptr<List_Node<T2>> tail = nullptr;
	int count = 0;
public:
	Linked_List(){}
	//appends a new node to the end
	std::shared_ptr<List_Node<T2>> push_back(const T2& load) {
		std::shared_ptr<List_Node<T2>> new_node = std::make_shared<List_Node<T2>>(load);
		if (count == 0) {
			head = new_node;
			tail = new_node;
		}
		else {
			tail->next = new_node;
			new_node->prev = tail;
			tail = new_node;
		}
		count++;
		tail = new_node;
		return new_node;
	}
	//removes specified node
	void remove(std::shared_ptr<List_Node<T2>> node) {
		std::shared_ptr<List_Node<T2>> p = node->prev;
		std::shared_ptr<List_Node<T2>> n = node->next;

		if (p!=nullptr) {
			p->next = n;
		}
		if (n != nullptr) {
			n->prev = p;
		}

		if (node==head) {
			head = n;
		}
		if (node==tail) {
			tail = p;
		}
	}
	//removes tail node and returns value
	T2 pop() {
		T2 l = tail->load;
		remove(tail);
		return l;
	}
	//inserts payload before given node
	void insert(std::shared_ptr<List_Node<T2>> destination, const T2& load) {
		std::shared_ptr<List_Node<T2>> new_node = std::make_shared<List_Node<T2>>(load);
		if (destination->prev!=nullptr) {
			(destination->prev)->next = new_node;
		}
		new_node->prev = destination->prev;
		destination->prev = new_node;
		new_node->next = destination;

		if (destination==head) {
			head = new_node;
		}
	}
	//moves node to before destination
	void move(std::shared_ptr<List_Node<T2>> destination, std::shared_ptr<List_Node<T2>> node) {
		//take node out
		if (node->prev!=nullptr) {
			node->prev->next = node->next;
		}
		if (node->next != nullptr) {
			node->next->prev = node->prev;
		}

		//put node before destination
		if (destination->prev!=nullptr) {
			destination->prev->next = node;
		}
		node->prev = destination->prev;
		destination->prev = node;
		node->next = destination;

		if (destination==head) {
			head = node;
		}
	}
	//swaps the postion of 2 elements
	void swap(std::shared_ptr<List_Node<T2>> first, std::shared_ptr<List_Node<T2>> second) {

		//update tail and head
	}
	auto front() {
		return head;
	}
	auto back() {
		return tail;
	}
	int size() {
		return count;
	}
	void print() {
		std::shared_ptr<List_Node<T2>> current = head;
		while (current!=nullptr) {
			if (current->prev != nullptr) {
				std::cout << current->prev->load;
			}
			else {
				std::cout << " ";
			}
			std::cout << ":" << current->load << ":";
			if (current->next!=nullptr) {
				std::cout << current->next->load;
			}

			std::cout << std::endl;
			current = current->next;
		}
	}
};