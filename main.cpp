//Copyright2023 Vishal Ahirwar.All rights reserved.
// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

	V::Array<int, 5> arr;
	for (uint16_t i = 0; i < arr.get_size()-1; ++i)arr.append(i);
	arr.insert(0, 14);
	arr.sort(comp);
	arr.binary_search(5);
	printf("Search and see how the array is shifting elements:)\n");
	for (;;)
	{
		arr.display();
		std::cout << "E : ";
		int input{};
		std::cin >> input;
		if (input == -1)break;
		arr.linear_search(input);
	}
}
