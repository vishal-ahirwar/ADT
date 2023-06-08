//Copyright2023 Vishal Ahirwar.All rights reserved.


#ifndef MACRO_ADT
#define MACRO_ADT
#include<iostream>
#include<typeinfo>
#include"Colours.h"

#define MACRO_TYPE template<typename DATA_TYPE, const int SIZE>

namespace V
{

	void show_error(const std::string& str) {
		printf("%s[Error] : %s\n", ANSI_COLOR_RED, str.c_str());
	};

	void show_warning(const std::string& str) {
		printf("%s[Warning] : %s\n", ANSI_COLOR_YELLOW, str.c_str());
	};

	void show_message(const std::string& str) {
		printf("%s[Message] : %s\n", ANSI_COLOR_RESET, str.c_str());
	};

	//Copyright2023 Vishal Ahirwar.
	MACRO_TYPE
		class Array
	{
	public:
		static void swap(DATA_TYPE& a, DATA_TYPE& b)
		{
			DATA_TYPE c = a;
			a = b;
			b = c;
		};

	public:


		Array() :size(SIZE), data(new DATA_TYPE[SIZE]), len(0) { show_warning("Constructor Called!"); };
		~Array()
		{
			if (this->data != nullptr)delete[]this->data;
		};


		const auto get_size()const { return this->size; };
		const auto get_len()const { return this->len; };
		const auto* get_ptr()const { return this->data; };


		void append(const DATA_TYPE&);

		int insert(const uint16_t& index, const DATA_TYPE& value);
		//TODO Binary Search
		int binary_search(const DATA_TYPE& value);

		int linear_search(const DATA_TYPE& value);
		//TODO Optimization of Linear Search
		//TODO Deleting Element From Array

		void display()const;

		DATA_TYPE operator [](uint16_t index)
		{
			if (index <= len)
			{
				return data[index];
			}
			else {
				return 0;
			}
		}
		;

	private:
		unsigned int size{};
		unsigned int len{};
		DATA_TYPE* data{ nullptr };
	};

	MACRO_TYPE
		inline void Array<DATA_TYPE, SIZE>::append(const DATA_TYPE& value)
	{
		if (len < size)
		{
			data[len++] = value;
		}
		else { show_error("Data structure is full"); };

	};

	MACRO_TYPE
		inline int Array<DATA_TYPE, SIZE>::insert(const uint16_t& index, const DATA_TYPE& value)
	{
		if (index > size || len == size)
		{
			show_error("Can't insert new element the structure is already full or the index is out of Array size!");
			return -1;
		}

		for (int i = len; i != index; --i)
		{
			data[i] = data[i - 1];
		};
		data[index] = value;
		++len;
		return 1;
	};

	MACRO_TYPE
		inline int Array<DATA_TYPE, SIZE>::binary_search(const DATA_TYPE& value)
	{
		return uint16_t();
	}
	MACRO_TYPE
		inline int Array<DATA_TYPE, SIZE>::linear_search(const DATA_TYPE& value)
	{
		for (uint16_t i = 0; i < len; ++i)
		{
			if (data[i] == value)
			{
				if (i == 0)return i;
				swap(data[i - 1], data[i]);//Memoization shifting elements slowly slowly
				/*swap(data[0], data[i]);*/
				return i-1;
			};
		};

		return -1;
	};
	MACRO_TYPE
		void Array<DATA_TYPE, SIZE>::display()const
	{
		show_message("Displaying Elements in Array : ");
		for (uint16_t i = 0; i < this->len; ++i)
		{
			std::cout << data[i] << ", ";
		};
		printf("\n");
	};

}
#endif