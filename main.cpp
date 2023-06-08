//Copyright2023 Vishal Ahirwar.All rights reserved.
// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"ADT.hpp"

int main()
{

	V::Array<int, 5> arr;
	for (int i = 0; i < arr.get_size(); ++i)arr.append(i);
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
