#ifndef FLATSTACK_H
#define FLATSTACK_H
#include <memory>
template <typename Data>
class FlatStack
{
public:
	FlatStack();
	FlatStack(size_t);
	void push(const Data&);
	void pop();
	void reserve(size_t);


private:
	size_t stack_size;
	size_t stack_capacity;
	const size_t growth_rate = 2;
	std::unique_ptr<Data[]> inner_array;
	std::unique_ptr<Data[ ]> tmparr;
	void shrink_to_fit();
};

template <typename Data>
FlatStack<Data>::FlatStack(){
	stack_size = 0;
	stack_capacity = 2;
	inner_array = std::unique_ptr<Data[ ]>(new Data[stack_capacity]);
}

template <typename Data>
FlatStack<Data>::FlatStack(size_t alloc){
	stack_size = 0;
	stack_capacity = alloc;
	inner_array = std::unique_ptr<Data[ ]>(new Data[stack_capacity]);
}

template <typename Data>
void FlatStack<Data>::push(const Data& value){
	if (stack_size < stack_capacity)
	{
		inner_array[stack_size++] = value;

	} else {
		stack_capacity *= growth_rate;
		tmparr = std::unique_ptr<Data[ ]>(new Data[stack_capacity]);

		std::copy(&inner_array[0], &inner_array[stack_size], &tmparr[0]);

		tmparr[stack_size++] = value;
		inner_array = std::move(tmparr);
	}
}

template <typename Data>
void FlatStack<Data>::pop(){
	stack_size--;

	if(stack_size < (stack_capacity / growth_rate)){
		this->shrink_to_fit();
	}
}

template <typename Data>
void FlatStack<Data>::shrink_to_fit(){
	stack_capacity = stack_size;

	tmparr = std::unique_ptr<Data[ ]>(new Data[stack_capacity]);

	for (size_t i = 0; i < stack_size; ++i)
		tmparr[i] = inner_array[i];

	inner_array = std::move(tmparr);
}

template <typename Data>
void FlatStack<Data>::reserve(size_t new_capacity){
	stack_capacity = new_capacity;

	tmparr = std::unique_ptr<Data[ ]>(new Data[stack_capacity]);

	std::copy(&inner_array[0], &inner_array[stack_size], &tmparr[0]);
	inner_array = std::move(tmparr);
}


#endif