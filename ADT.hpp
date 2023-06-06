

#ifndef MACRO_ADT
#define MACRO_ADT
#include<stdio.h>
#include<typeinfo>


#define MACRO_TYPE template<typename DATA_TYPE, const int SIZE>


//Copyright2023 Vishal Ahirwar.
MACRO_TYPE
class Array
{
private:
	void swap(DATA_TYPE& a, DATA_TYPE& b)
	{
		DATA_TYPE c = a;
		a = b;
		b = c;
	};

public:


	Array() :size(SIZE), data(new DATA_TYPE[SIZE]), len(0) {};
	~Array()
	{
		if (this->data != nullptr)delete[]this->data;
	};
	
	
	const auto get_size()const { return this->size; };
	const auto get_len()const { return this->len; };
	const auto * get_ptr()const { return this->data; };

	//TODO Add/Append
	void append(const DATA_TYPE&);
	//TODO Insert
	uint16_t insert(const uint16_t& index, const DATA_TYPE& value);
	//TODO Binary Search
	uint16_t binary_search(const DATA_TYPE& value);
	//TODO Linear Search
	uint16_t linear_search(const DATA_TYPE& value);
	//TODO Optimization of Linear Search
	//TODO Deleting Element From Array

	void display()const;

private:
	unsigned int size{};
	unsigned int len{};
	DATA_TYPE* data;
};

MACRO_TYPE
inline void Array<DATA_TYPE,SIZE>::append(const DATA_TYPE&)
{
}
MACRO_TYPE
inline uint16_t Array<DATA_TYPE,SIZE>::insert(const uint16_t& index, const DATA_TYPE& value)
{
	return uint16_t();
}
MACRO_TYPE
inline uint16_t Array<DATA_TYPE,SIZE>::binary_search(const DATA_TYPE& value)
{
	return uint16_t();
}
MACRO_TYPE
inline uint16_t Array<DATA_TYPE, SIZE>::linear_search(const DATA_TYPE& value)
{
	return uint16_t();
};
MACRO_TYPE
void Array<DATA_TYPE, SIZE>::display()const
{
	for (auto i = 0; i < this->len; ++i)
	{
		printf("%s", this->data[i]);
	};
	printf("\n");
};

#endif