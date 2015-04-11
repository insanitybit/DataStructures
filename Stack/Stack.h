#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <memory>
#include <assert.h>
/*
Traditional, non-flat stack.
*/
template<class Data>
class Stack
{
public:
	Stack();
	void push(const Data&);
	void pop();
	Data& top();
	size_t stack_size;

private:
	size_t size();

	struct Node
	{
		Data data;
		std::shared_ptr<Node> below;
	};

	std::shared_ptr<Node> tail;
	
};

template<class Data>
Stack<Data>::Stack(){
	stack_size = 0;
}

template<class Data>
void Stack<Data>::push(const Data& d){
	std::shared_ptr<Node> node(new Node);
	node->data = d;
	node->below = tail;
	tail = node;

	stack_size++;
}

template<class Data>
void Stack<Data>::pop(){
	assert(stack_size > 0);

	tail = tail->below;
	stack_size--;
}

template<class Data>
size_t Stack<Data>::size(){
	return stack_size;
}

template<class Data>
Data& Stack<Data>::top(){
	return tail->data;
}

#endif