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
	Single_Node<T>* push_back(const T& load) {
		Single_Node<T>* new_node = new Single_Node(load);
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
	void remove(Single_Node<T>* node) {
		Single_Node<T>* previous = find_previous(node);
		Single_Node<T>* next = node->next;

		//change the previous node's next pointer
		if (previous!=nullptr) {
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
	T pop() {
		T l = tail->load;
		remove(tail);
		return l;
	}
	//inserts payload before given node
	Single_Node<T>* insert(Single_Node<T>* destination, const T& load) {
		Single_Node<T>* new_node = new Single_Node<T>(load);
		Single_Node<T>* previous = find_previous(destination);

		previous->next = new_node;
		new_node->next = destination;

		return new_node;
	}
	void move() {}
	void swap() {}
	void reverse() {}
	//find previous node
	Single_Node<T>* find_previous(Single_Node<T>* node) {
		Single_Node<T>* current = head;
		Single_Node<T>* previous = nullptr;

		//find previous node
		while (current != node && current!=nullptr) {
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
	Single_Node<T>* find(const T& val) {
		Single_Node<T>* current = head;
		while (current!=nullptr) {
			if (current->load==val) {
				return current;
			}
			current = current->next;
		}
		return nullptr;//value not in list
	}
	//empties list
	void clear() {
		//free nodes
		Single_Node<T>* current = head;
		Single_Node<T>* next = nullptr;
		while (current != nullptr) {
			next = current->next;
			delete current;
			current = next;
		}

		//reset vars
		count = 0;
		head = nullptr;
		tail = nullptr;
	}
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