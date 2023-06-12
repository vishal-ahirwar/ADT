//Copyright2023 Vishal Ahirwar.All rights reserved.
// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
* {
//V::Array<int, 15>arr1;
//for (uint16_t i = 0; i < arr1.get_size() - 1; ++i)arr1.append(i * i);
//arr.display();
//arr1.display();
//V::merge(arr, arr1);
//arr.display();
//arr.insert(0, 14);
//arr.sort(comp);
//arr.binary_search(5);
}
*/

#include"ADT.hpp"
int comp(const void* elem1, const void* elem2)
{
	int f = *((int*)elem1);
	int s = *((int*)elem2);
	if (f > s) return  1;
	if (f < s) return -1;
	return 0;
};

int main()
{

	V::Array<std::string, 5> arr;
	for (uint16_t i = 0; i < arr.get_size() - 1; ++i)arr.append("Hello");
	for (uint16_t i = 0; i < arr.get_size() - 1; ++i)arr[i]->insert(std::begin(*arr[i]),char(i+"0"));

	printf("search and see how the array is shifting elements:)\n");
	for (;;)
	{
		arr.display();
		std::cout << "e : ";
		std::string input{};
		std::cin >> input;
		if (input == "quit")break;
		arr.linear_search(input);
	}
};

