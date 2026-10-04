#include "LinkedList.h"
#include <iostream>

void test_push_back() {
	auto list = Linked_List<std::string>();

	std::cout << "------------push_back()-------------" << std::endl;
	std::cout << list << std::endl;

	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");
	
	std::cout << list << std::endl;
}

void test_pop() {
	auto list = Linked_List<std::string>();
	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");

	std::cout << "------------pop()-------------" << std::endl;
	std::cout << list << std::endl;

	list.pop();

	std::cout << list << std::endl;
}

void test_remove() {
	auto list = Linked_List<std::string>();
	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");

	std::cout << "------------remove(b)-------------" << std::endl;
	std::cout << list << std::endl;

	list.remove(b);

	std::cout << list << std::endl;
}

void test_insert() {
	auto list = Linked_List<std::string>();
	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");


	std::cout << "------------insert(c, \"F\")------------ - " << std::endl;
	std::cout << list << std::endl;

	list.insert(c, "F");

	std::cout << list << std::endl;
}

void test_move() {
	auto list = Linked_List<std::string>();
	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");


	std::cout << "------------move(a, d)------------ - " << std::endl;
	std::cout << list << std::endl;

	list.move(a, d);

	std::cout << list << std::endl;
}

void test_swap() {
	auto list = Linked_List<std::string>();
	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");
	auto list2 = Linked_List<std::string>();
	auto a2 = list2.push_back("1");
	auto b2 = list2.push_back("2");
	auto c2 = list2.push_back("3");
	auto d2 = list2.push_back("4");
	auto e2 = list2.push_back("5");

	std::cout << "------------swap(list2)------------ - " << std::endl;

	std::cout << list << std::endl;
	std::cout << list2 << std::endl;

	list.swap(list2);

	std::cout << list << std::endl;
	std::cout << list2 << std::endl;
}

void test_reverse() {
	auto list = Linked_List<std::string>();
	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");

	std::cout << "------------reverse()-------------" << std::endl;
	std::cout << list << std::endl;

	list.reverse();

	std::cout << list << std::endl;
}

void test_find() {
	auto list = Linked_List<std::string>();
	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");

	std::cout << "------------find(\"B\")-------------" << std::endl;
	std::cout << list << std::endl;

	auto found = list.find("B");

	std::cout << found->load << std::endl;
}

int main(int argc, char* argv) {
	test_push_back();
	test_remove();
	test_insert();
	test_move();
	test_swap();
	test_reverse();
	test_find();
	return 0;
}
