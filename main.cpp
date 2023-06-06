//Copyright2023 Vishal Ahirwar.All rights reserved.
// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"ADT.hpp"

int main()
{

	V::Array<int, 5> arr;
	for (uint16_t i = 0; i < arr.get_size(); ++i)arr.append(i * i);
	//auto index = arr.linear_search(16);
	if (auto index = arr.linear_search(15); index == -1)
	{
		V::show_error("Not found!");
	}
	else
	{
		V::show_message("Found!");
	};

	if (int index = arr.linear_search(16); index == -1)
	{
		V::show_error("not found!");
	}
	else
	{
		V::show_message("found!");
	};
}
