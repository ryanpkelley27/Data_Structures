#include "LinkedList.h"
#include <iostream>

int main(int argc, char* argv) {
	auto list = Linked_List<std::string>();

	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");
	list.print();
	std::cout << std::endl;

	list.pop();//remove e
	list.print();
	std::cout << std::endl;

	list.remove(b);//remove b
	list.print();
	std::cout << std::endl;

	list.insert(c, "F");
	list.print();
	std::cout << std::endl;

	list.move(a, d);
	list.print();
	std::cout << std::endl;

	return 0;
}
