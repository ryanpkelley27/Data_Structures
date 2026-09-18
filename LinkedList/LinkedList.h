#pragma once
#include <memory>
#include <iostream>

template <typename T2> class Linked_List;

template <typename T>
class List_Node {
	friend class Linked_List<T>;
private:
	T load;
	//doubly linked
	std::shared_ptr<List_Node<T>> next;
	std::shared_ptr<List_Node<T>> prev;
public:
	List_Node(int load, std::shared_ptr<List_Node<T>> next = nullptr, std::shared_ptr<List_Node<T>> prev = nullptr) : load(load), next(next), prev(prev) {}
};

template <typename T2>
class Linked_List {
private:
	std::shared_ptr<List_Node<T2>> head = nullptr;
	std::shared_ptr<List_Node<T2>> tail = nullptr;
	int count = 0;
public:
	Linked_List(){}
	void push_back(const T2& load) {
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
	}
	//removes specified node
	void remove(std::shared_ptr<List_Node<T2>> node) {
		std::shared_ptr<List_Node<T2>> p = node->prev;
		std::shared_ptr<List_Node<T2>> n = node->next;

		if (p!=nullptr) {
			p->next = n;
		}
		if (n!=nullptr) {
			n->prev = p;
		}
	}
	//removes tail node and returns value
	T2 pop(std::shared_ptr<List_Node<T2>> node) {

	}
	//inserts payload before given node
	void insert(std::shared_ptr<List_Node<T2>> destination, const T2& load) {

	}
	//moves node to destination
	void move(std::shared_ptr<List_Node<T2>> destination, std::shared_ptr<List_Node<T2>> node) {

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
			std::cout << current->load << std::endl;
			current = current->next;
		}
	}
};