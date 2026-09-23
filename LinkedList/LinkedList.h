#pragma once
#include <memory>
#include <iostream>
#include <string>

template <typename T> class Linked_List;

template <typename T>
class List_Node {
	friend class Linked_List<T>;
public:
	T load;
	//doubly linked
	std::shared_ptr<List_Node<T>> next;
	std::shared_ptr<List_Node<T>> prev;
	List_Node(T load, std::shared_ptr<List_Node<T>> next = nullptr, std::shared_ptr<List_Node<T>> prev = nullptr) : load(load), next(next), prev(prev) {}

	template <typename T> friend std::ostream& operator<<(std::ostream& out, const std::shared_ptr<List_Node<T>>& ln);
	template <typename T> friend std::ostream& operator<<(std::ostream& out, const List_Node<T>& ln);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::shared_ptr<List_Node<T>>& ln) {
	out << ln->load;
	return out;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const List_Node<T>& ln) {
	out << ln.load;
	return out;
}

template <typename T>
class Linked_List {
private:
	std::shared_ptr<List_Node<T>> head = nullptr;
	std::shared_ptr<List_Node<T>> tail = nullptr;
	int count = 0;
public:
	Linked_List(){}
	//appends a new node to the end
	std::shared_ptr<List_Node<T>> push_back(const T& load) {
		std::shared_ptr<List_Node<T>> new_node = std::make_shared<List_Node<T>>(load);
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
	void remove(std::shared_ptr<List_Node<T>> node) {
		std::shared_ptr<List_Node<T>> p = node->prev;
		std::shared_ptr<List_Node<T>> n = node->next;

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
	T pop() {
		T l = tail->load;
		remove(tail);
		return l;
	}
	//inserts payload before given node
	void insert(std::shared_ptr<List_Node<T>> destination, const T& load) {
		std::shared_ptr<List_Node<T>> new_node = std::make_shared<List_Node<T>>(load);
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
	void move(std::shared_ptr<List_Node<T>> destination, std::shared_ptr<List_Node<T>> node) {
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
	void swap(std::shared_ptr<List_Node<T>> first, std::shared_ptr<List_Node<T>> second) {


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

	template <typename T> friend std::ostream& operator<<(std::ostream& out, const Linked_List<T>& ll);
};

//overload << operator for ostreams
template <typename T>
std::ostream& operator<<(std::ostream& out, const Linked_List<T>& ll) {
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