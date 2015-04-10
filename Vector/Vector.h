#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <algorithm>
#include <stdlib.h>
template<class T>
class Vector
{
public:
	Vector();
	// Vector(Vector<T>&);
	// Vector(Vector<T>&&);

	Vector(const size_t);

	void push_back(const T& value);
	void push_back(const T&& value);
	void pop_back();
	bool contains(T&);
	bool contains(T&&);

	T& at(const size_t index);
	T& operator[] (const size_t i) { return inner_array[i]; };
	const T& operator[] (const size_t i) const { return inner_array[i]; };

	void resize(const size_t);
	void shrink_to_fit();

	size_t capacity();
	size_t size();

	std::unique_ptr<T[ ]>& data();

private:
	size_t inner_size;
	size_t inner_capacity;
	size_t growth_rate = 2;

	std::unique_ptr<T[ ]> inner_array;
	std::unique_ptr<T[ ]> tmparr;
};

template<class T> Vector<T>::Vector(){
	inner_array = std::unique_ptr<T[ ]>(new T[2]);
	inner_capacity = 2;
	inner_size = 0;
}

// // // copy constructor
// template<class T> Vector<T>::Vector(Vector<T>& v){
// 	inner_array = std::unique_ptr<T[ ]>(new T[v.size()]);
// 	inner_capacity = v.capacity();
// 	inner_size = v.size();
// 	growth_rate = v.get_growth_rate();

// 	for (size_t i = 0; i < inner_size; ++i)
// 		inner_array[i] = v.data()[i];

// 	// std::copy(&inner_array[0], &inner_array[inner_size], &v.data()[0]); can't figure out why this is not working

// // // rval constructor
// template<class T> Vector<T>::Vector(Vector<T>&& v){
// 	inner_array = std::unique_ptr<T[ ]>(new T[v.size()]);
// 	inner_capacity = v.capacity();
// 	inner_size = v.size();
// 	growth_rate = v.get_growth_rate();
// 	inner_array = std::move(v.data());
// }

template<class T>
Vector<T>::Vector(const size_t count){
	inner_array = std::unique_ptr<T[ ]>(new T[count]);
	if (count < 2)
		inner_capacity = 2;
	else
		inner_capacity = count;

	inner_size = count;
}

template<class T>
T& Vector<T>::at(const size_t index){
	// assert(index < inner_size);
	return inner_array[index];
}

template<class T>
void Vector<T>::push_back(const T& value){
	if (inner_size < inner_capacity)
	{
		inner_array[inner_size++] = value;

	} else {
		inner_capacity *= growth_rate;
		tmparr = std::unique_ptr<T[ ]>(new T[inner_capacity]);

		for (size_t i = 0; i < inner_size; ++i)
			inner_array[i] = std::move(tmparr[i]);


		tmparr[inner_size++] = value;
		inner_array = std::move(tmparr);
	}
}

template<class T> void Vector<T>::push_back(const T&& value){
	if (inner_size < inner_capacity)
	{
		inner_array[inner_size++] = std::move(value);

	} else {
		inner_capacity *= growth_rate;
		tmparr = std::unique_ptr<T[ ]>(new T[inner_capacity]);

		for (size_t i = 0; i < inner_size; ++i)
			inner_array[i] = std::move(tmparr[i]);

		tmparr[inner_size++] = std::move(value);
		inner_array = std::move(tmparr);
	}
}


template<class T> void Vector<T>::pop_back(){
	inner_size--;
}

template<class T> void Vector<T>::resize(const size_t new_size){
	inner_size = new_size;

	inner_capacity = inner_size;
	tmparr = std::unique_ptr<T[ ]>(new T[inner_capacity]);


		for (size_t i = 0; i < inner_size; ++i)
			inner_array[i] = std::move(tmparr[i]);


	inner_array = std::move(tmparr);
}

template<class T> void Vector<T>::shrink_to_fit(){
	inner_capacity = inner_size;

	tmparr = std::unique_ptr<T[ ]>(new T[inner_capacity]);

	for (size_t i = 0; i < inner_size; ++i)
		tmparr[i] = inner_array[i];

	inner_array = std::move(tmparr);
}


template<class T> size_t Vector<T>::capacity(){
	return inner_capacity;
}

template<class T> size_t Vector<T>::size(){
	return inner_size;
}

template<class T> std::unique_ptr<T[ ]>& Vector<T>::data(){
	return inner_array;
}

template<class T>
bool Vector<T>::contains(T& t){
	for (size_t i = 0; i < inner_size; i++) {
		if(inner_array[i] == t)
			return true;
	}
	return false;
}

template<class T>
bool Vector<T>::contains(T&& t){
	for (size_t i = 0; i < inner_size; i++) {
		if(inner_array[i] == t)
			return true;
	}
	return false;
}

#endif
