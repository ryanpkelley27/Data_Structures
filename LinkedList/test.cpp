#include "LinkedList.h"
#include <iostream>

int main(int argc, char* argv) {
	auto list = Linked_List<int>();

	list.push_back(11);
	list.push_back(22);
	list.push_back(33);
	list.push_back(44);
	list.push_back(55);
	list.print();
	std::cout << std::endl;
	list.remove(list.back());
	list.print();

	return 0;
}
