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
	std::shared_ptr<List_Node<T>> push_back(const T& load) {
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
		count--;
	}
	//removes tail node and returns value
	T pop() {
		T l = tail->load;
		remove(tail);
		count--;
		return l;
	}
	//inserts payload before given node
	std::shared_ptr<List_Node<T>> insert(std::shared_ptr<List_Node<T>> destination, const T& load) {
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

		count++;
		return new_node;
	}
	//moves node to before destination
	void move(std::shared_ptr<List_Node<T>> destination, std::shared_ptr<List_Node<T>> node) {
		//update tail
		if (node == tail) {
			tail = node->prev;
		}

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

		//update head
		if (destination==head) {
			head = node;
		}
	}
	//swaps the elements of two lists without moving elements
	void swap(Linked_List<T>& other) {
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
	void reverse() {
		//nothing to reverse
		if (count==0) {
			return;
		}

		//iteraste and switch next and prev
		auto current = head;
		auto temp = current->next;

		while (current!=nullptr) {
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
	std::shared_ptr<List_Node<T>> find(T val) {
		auto current = head;
		while (current!=nullptr) {
			if (current->load==val) {
				return current;
			}
			current = current->next;
		}

		return nullptr;
	}
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
std::ostream& operator<<(std::ostream& out, const Linked_List<T>& ll) {
	if (ll.count==0) {
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