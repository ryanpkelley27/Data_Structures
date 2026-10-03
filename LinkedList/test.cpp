#include "LinkedList.h"
#include <iostream>

int main(int argc, char* argv) {
	auto list = Linked_List<std::string>();

	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");
	std::cout << list << std::endl;

	list.pop();//remove e
	std::cout << list << std::endl;

	list.remove(b);//remove b
	std::cout << list << std::endl;

	auto f = list.insert(c, "F");//puts "F" before "C"
	std::cout << list << std::endl;

	list.move(a, d);
	std::cout << list << std::endl;

	std::cout << "-----------------" << std::endl;
	auto list2 = Linked_List<std::string>();
	auto a2 = list2.push_back("1");
	auto b2 = list2.push_back("2");
	auto c2 = list2.push_back("3");
	auto d2 = list2.push_back("4");
	auto e2 = list2.push_back("5");

	std::cout << list2 << std::endl;

	list.swap(list2);

	std::cout << list << std::endl;
	std::cout << list2 << std::endl;

	return 0;
}
