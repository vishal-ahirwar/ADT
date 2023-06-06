// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"ADT.hpp"

int main()
{

	Array<int,5> arr;
	for (int i = 0; i < arr.get_size(); ++i)arr.append(i * i);
	//auto index = arr.linear_search(16);
	if (auto index = arr.linear_search(15); index == -1)
	{
		show_error("Not found!");
	}
	else
	{
		show_message("Found!");
	};

	if (int index = arr.linear_search(16); index == -1)
	{
		show_error("not found!");
	}
	else
	{
		show_message("found!");
	};


	//arr.append("Hello");
	//arr.append("World");
	//arr.insert(1, "Chooo");
	//arr.insert(6, "heeh");
	//arr.append("hehe");
	//arr.append("what");


	arr.display();

}
