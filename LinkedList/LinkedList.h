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

	template <typename T> friend std::ostream& operator<<(std::ostream& out, const std::shared_ptr<List_Node<T>> ln);
	template <typename T> friend std::ostream& operator<<(std::ostream& out, const List_Node<T>& ln);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::shared_ptr<List_Node<T>> ln) {
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
	std::shared_ptr<List_Node<T>> push_back(const T& load);
	//removes specified node
	void remove(std::shared_ptr<List_Node<T>> node);
	//removes tail node and returns value
	T pop();
	//inserts payload before given node
	std::shared_ptr<List_Node<T>> insert(std::shared_ptr<List_Node<T>> destination, const T& load);
	//moves node to before destination
	void move(std::shared_ptr<List_Node<T>> destination, std::shared_ptr<List_Node<T>> node);
	//swaps the elements of two lists without moving elements
	void swap(Linked_List<T>& other);
	//reverses list
	void reverse();
	//find based on value - return pointer to node
	std::shared_ptr<List_Node<T>> find(T val);
	//empties list
	void clear() {
		head = nullptr;
		tail = nullptr;
		count = 0;
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
std::ostream& operator<<(std::ostream& out, const Linked_List<T>& ll);

#include "LinkedList.cpp"