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

	list.insert(c, "F");
	std::cout << list << std::endl;

	list.move(a, d);
	std::cout << list << std::endl;

	return 0;
}
