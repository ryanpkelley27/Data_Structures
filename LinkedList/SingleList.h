#pragma once
#include <iostream>
#include <string>

template <typename T> class Single_List;

template <typename T>
class Single_Node {
	friend class Single_List<T>;
public:
	T load;
	//singly linked
	Single_Node<T>* next;
	Single_Node(T load, Single_Node<T>* next = nullptr) : load(load), next(next) {}

	template <typename T> friend std::ostream& operator<<(std::ostream& out, const Single_Node<T>& ln);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Single_Node<T>& ln) {
	out << ln.load;
	return out;
}

template <typename T>
class Single_List {
private:
	Single_Node<T>* head = nullptr;
	Single_Node<T>* tail = nullptr;
	int count = 0;
public:
	Single_List() {}
	~Single_List() {
		clear();
	}
	//add node to the end
	Single_Node<T>* push_back(const T& load);
	//remove specified node
	void remove(Single_Node<T>* node);
	//removes tail node and returns copy of value
	T pop();
	//inserts payload before given node
	Single_Node<T>* insert(Single_Node<T>* destination, const T& load);
	void move(Single_Node<T>* destination, Single_Node<T>* node);
	void swap();
	void reverse();
	//find previous node
	Single_Node<T>* find_previous(Single_Node<T>* node);
	//find node by value
	Single_Node<T>* find(const T& val);
	//empties list
	void clear();
	void front() {
		return head;
	}
	void back() {
		return tail;
	}
	void size() {
		return count;
	}

	template <typename T> friend std::ostream& operator<<(std::ostream& out, const Single_List<T>& sl);
};

//overload << operator for ostreams
template <typename T>
std::ostream& operator<<(std::ostream& out, const Single_List<T>& sl);

#include "SingleList.cpp"