//Copyright2023 Vishal Ahirwar.All rights reserved.


#ifndef MACRO_ADT
#define MACRO_ADT
#include<iostream>
#include<typeinfo>
#include"Colours.h"
#include<stdlib.h>
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
			show_warning("destructor Called!");
		};

		const auto get_size()const { return this->size; };
		const auto get_len()const { return this->len; };
		const auto* get_ptr()const { return this->data; };


		void append(const DATA_TYPE&);

		void sort(int(*function)(const void*,const void*));
		int insert(const uint16_t& index, const DATA_TYPE& value);
		//TODO Binary Search
		int binary_search(const DATA_TYPE& value);

		int linear_search(const DATA_TYPE& value);
		//TODO Optimization of Linear Search
		//TODO Deleting Element From Array
		//TODO Reversing Array
		//TODO LeftShift()
		//TODO RightShift()
		//TODO LeftRotate()
		//TODO RightRotate()
		//TODO Merging Arrays

		
			template<class DATA_TYPE, int SIZE, int SIZE2>
			friend void merge(Array<DATA_TYPE, SIZE>& arr, const Array<DATA_TYPE, SIZE2>& arr1);

		void display()const;

		DATA_TYPE* operator [](uint16_t index)
		{
			if (index <= len)
			{
				return &data[index];
			}
			else {
				return nullptr;
			}
		}
		;

	private:
		unsigned int size{};
		unsigned int len{};
		DATA_TYPE* data{ nullptr };
		bool b_sorted{ false };
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
		if (!b_sorted)
		{
			show_error("Array iss not sorted");
				return -1;
		};
		unsigned int low{0}, high{ this->len }, mid{0};
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (value == data[mid])return mid;
			else if (value < data[mid])high = mid - 1;
			else if (value > data[mid])low = mid + 1;
		};
		return int(-1);
	}
	MACRO_TYPE
		inline int Array<DATA_TYPE, SIZE>::linear_search(const DATA_TYPE& value)
	{
		b_sorted = false;
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
	MACRO_TYPE
		void Array<DATA_TYPE, SIZE>::sort(int(*function)(const void*,const void*))
	{
		qsort(data, len, sizeof(DATA_TYPE), function);
		b_sorted = true;
	};

template<class DATA_TYPE,int SIZE,int SIZE2>
	void merge(Array<DATA_TYPE,SIZE>&arr,const Array<DATA_TYPE,SIZE2>&arr1)
	{
		DATA_TYPE* new_data = new DATA_TYPE[arr.len + arr1.len];
		unsigned i{};
		for (i = 0; i < arr.len; ++i)new_data[i] = arr.data[i];
		for (unsigned j = 0; j < arr1.len; ++j,++i)new_data[i] = arr1.data[j];
		delete[] arr.data;
		arr.len += arr1.len;
		arr.size += arr1.size;
		arr.data = new_data;
		new_data = nullptr;
	};

}
#endif