#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <new>
#include "node.h"

using namespace std;

class StackEmpty : public runtime_error {
	public:
		StackEmpty() : runtime_error("Stack Empty"){}
		StackEmpty (const string &what) : runtime_error(what){}
};



template <typename T>
class Stack{
	public:
		Stack();
		Stack(const Stack<T> &s) throw(bad_alloc);
		bool empty() const;
		unsigned size() const;
		T &top() const throw(StackEmpty);
		T pop() throw(StackEmpty);
		void push (const T&) throw(bad_alloc);
		const Stack<T> &operator = (const Stack<T> &s) throw(bad_alloc);
		void printInternal() const;
		void clear();
		void printInternal();
		~Stack();

	private:
		unsigned sz;
		Node<T> *topPtr;
		void initialize();
};//Stack

template <typename T>
void Stack<T>::initialize(){
	sz = 0;
	topPtr=0; 
}

template <typename T>
Stack<T>::Stack(){
	initialize();
}

template <typename T>
Stack<T>::Stack(const Stack<T> &s) throw(bad_alloc){
	initialize();
	*this = s;
}

template <typename T>
bool Stack<T>::empty() const{ 	
	return (topPtr == 0);
}

template <typename T>
unsigned Stack<T>::size() const{
	return sz;
}

template <typename T>
T& Stack<T>::top() const throw (StackEmpty){
	if (empty())
		throw StackEmpty("top: stack empty");		
return topPtr->getObject;
}

template <typename T>
T Stack<T>::pop() throw(StackEmpty){
	if(empty())
		throw StackEmpty ("pop: stack empty");
	Node<T> *ptr = topPtr;
	topPtr = topPtr->getNextPtr();
	T value = ptr->getObject();
	delete ptr;
	sz--;
	return value;
}

template <typename T>
void Stack<T>::push(const T &item) throw(bad_alloc){
	Node<T> *ptr = new Node<T> (item);
	ptr->setNextPtr(topPtr);
	topPtr = ptr;
	sz++;
}

template <typename T>
void Stack<T>::clear(){
	Node<T> *ptr = topPtr;
	while (topPtr != 0){
		topPtr = topPtr->getNextPtr();
		delete ptr;
		ptr = topPtr;
	}
initialize();
}

template <typename T>
Stack<T>:: ~Stack(){
	clear();
}

template <typename T>
const Stack<T> &Stack<T>:: operator = (const Stack<T> &s) throw (bad_alloc){
	cout<<"*"<<endl;
	if (&s != this){
		cout<<"*"<<endl;
		if(!empty()) clear();
		sz = s.sz;
		Node<T> *sptr = s.topPtr;
		Node<T> *last = 0;
		cout<<"*"<<endl;
		while (sptr != 0){
			cout<<"****"<<endl;
			if(last == 0)
				topPtr = last = new Node<T>(*sptr);
		
			else{
				last->setNextPtr(new Node<T> (*sptr));
				last = last->getNextPtr();
			}//else
			sptr = sptr->getNextPtr();
		}//while
	}//if
	return *this;
}



template <typename T>
void Stack<T>::printInternal(){
	Node<T> *current = topPtr;
	int i=0;
	cout<<"top: "<<topPtr<<endl;
	while (current !=0){
		cout<<"Node: "<<i<<endl;
		//cout<<"Address: "<<current <<endl;
		cout<<"contents: "<<current->getObject()<<endl;
		//cout<<"next ptr: "<<current->getNextPtr()<<endl;
		current = current->getNextPtr();
		i++;
	}//while
}//printInternal()

#endif






