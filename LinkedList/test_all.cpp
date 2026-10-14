#include "Windows.h"//for OutputDebugString
#ifdef _DEBUG
	#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#else
	#define DBG_NEW new
#endif

#include "LinkedList.h"
#include "SingleList.h"
#include <iostream>

static void test_list_push_back(Linked_List<std::string>& list) {
	list.clear();

	std::cout << "------------push_back()-------------" << std::endl;
	std::cout << list << std::endl;

	list.push_back("A");
	list.push_back("B");
	list.push_back("C");
	list.push_back("D");
	list.push_back("E");
	
	std::cout << list << std::endl;
}

static void test_list_pop(Linked_List<std::string>& list) {
	list.clear();
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

static void test_list_remove(Linked_List<std::string>& list) {
	list.clear();
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

static void test_list_insert(Linked_List<std::string>& list) {
	list.clear();

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

static void test_list_move(Linked_List<std::string>& list) {
	list.clear();
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

static void test_list_swap(Linked_List<std::string>& list) {
	list.clear();
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

static void test_list_reverse(Linked_List<std::string>& list) {
	list.clear();
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

static void test_list_find(Linked_List<std::string>& list) {
	list.clear();
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

//------------------------------------------------------------------------------------------------------------------------

static void test_single_push_back(Single_List<std::string>& list) {
	list.clear();

	std::cout << "------------push_back()-------------" << std::endl;
	std::cout << list << std::endl;

	auto a = list.push_back("A");
	auto b = list.push_back("B");
	auto c = list.push_back("C");
	auto d = list.push_back("D");
	auto e = list.push_back("E");

	std::cout << list << std::endl;
}

static void test_single_pop(Single_List<std::string>& list) {
	list.clear();
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

static void test_single_remove(Single_List<std::string>& list) {
	list.clear();
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

static void test_single_insert(Single_List<std::string>& list) {
	list.clear();

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

static void test_single_move(Single_List<std::string>& list) {
	list.clear();
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

int main(int argc, char* argv) {
	_CrtMemState s_1;
	_CrtMemState s_2;
	_CrtMemState s_3;
	_CrtMemState s_diff;

	_CrtMemCheckpoint(&s_1);

	auto list = Linked_List<std::string>();

	test_list_push_back(list);
	test_list_pop(list);
	test_list_remove(list);
	test_list_insert(list);
	test_list_move(list);
	test_list_swap(list);
	test_list_reverse(list);
	test_list_find(list);
	list.clear();
	
	_CrtMemCheckpoint(&s_2);

	auto single = Single_List<std::string>();

	test_single_push_back(single);
	test_single_pop(single);
	test_single_remove(single);
	test_single_insert(single);
	test_single_move(single);
	single.clear();

	_CrtMemCheckpoint(&s_3);

	OutputDebugString(L"------------Doubly Linked List------------\n");
	if (_CrtMemDifference(&s_diff, &s_1, &s_2)) {
		_CrtMemDumpStatistics(&s_diff);
	}
	else {
		OutputDebugString(L"No Leaks Detected\n");
	}

	OutputDebugString(L"------------Singly Linked List------------\n");
	if (_CrtMemDifference(&s_diff, &s_2, &s_3)) {
		
		_CrtMemDumpStatistics(&s_diff);
	}
	else {
		OutputDebugString(L"No Leaks Detected\n");
	}

	//_CrtDumpMemoryLeaks();

	return 0;
}
