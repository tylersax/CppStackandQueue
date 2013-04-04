#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <new>

using namespace std;

template <typename T>
class Node {
	private:
		T object;
		Node<T> *nextPtr;	  
	public: 
		Node (const T &object =Node());
		void setObject(const T&);
		T & getObject();
		void setNextPtr(Node<T> *nextPtr);
		Node<T>* getNextPtr() const;
};

template <typename T>
Node<T>::Node(const T &object){
	this->object = object;
	this->nextPtr = 0;
}

template <typename T>
void Node <T>::setObject(const T &object){
	this->object=object;
}

template <typename T>
T& Node <T>::getObject(){
	return object;
}

template <typename T>
void Node<T>::setNextPtr(Node<T> *nextPtr){
	this->nextPtr=nextPtr;
}

template <typename T>
Node<T>* Node<T>::getNextPtr() const{
	return nextPtr;
}

#endif
