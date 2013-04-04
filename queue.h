#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <new>
#include "node.h"

using namespace std;

class QueueEmpty : public runtime_error {
	public:
		QueueEmpty() : runtime_error("Queue Empty"){}
		QueueEmpty (const string &what) : runtime_error(what){}
};



template <typename T>
class Queue{
	public:
		Queue();
		Queue(const Queue<T> &s) throw(bad_alloc);
		bool empty() const;
		unsigned size() const;
		T &front() const throw(QueueEmpty);
		T dequeue() throw(QueueEmpty);
		void enqueue (const T&) throw(bad_alloc);
		const Queue<T> &operator = (const Queue<T> &) throw(bad_alloc);
		void printInternal() const;
		void clear();
		void printInternal();
		~Queue();

	private:
		unsigned sz;
		Node<T> *frontPtr;
		Node<T> *backPtr;
		void initialize();
};//Queue

template <typename T>
void Queue<T>::initialize(){
	sz = 0;
	frontPtr=0; 
	backPtr=0;
}

template <typename T>
Queue<T>::Queue(){
	initialize();
}

template <typename T>
Queue<T>::Queue(const Queue<T> &s) throw(bad_alloc){
	initialize();
	*this = s;
}

template <typename T>
bool Queue<T>::empty() const{ 	
	return (frontPtr == 0);
}

template <typename T>
unsigned Queue<T>::size() const{
	return sz;
}

template <typename T>
T& Queue<T>::front() const throw (QueueEmpty){
	if (empty())
		throw QueueEmpty("Front(): Queue empty");		
return frontPtr->getObject;
}

template <typename T>
T Queue<T>::dequeue() throw(QueueEmpty){
	if(empty())
		throw QueueEmpty ("Dequeue: Queue empty");
	Node<T> *ptr = frontPtr;
	frontPtr = frontPtr->getNextPtr();
	T value = ptr->getObject();
	delete ptr;
	sz--;
	return value;
}

template <typename T>
void Queue<T>::enqueue(const T &item) throw(bad_alloc){
	Node<T> *ptr = new Node<T> (item);
	if (frontPtr == 0)
		frontPtr = ptr;
	if (backPtr != 0){
		backPtr->setNextPtr(ptr);
	}
	backPtr = ptr;
	sz++;
}

template <typename T>
void Queue<T>::clear(){
	Node<T> *ptr = frontPtr;
	while (frontPtr != 0){
		frontPtr = frontPtr->getNextPtr();
		delete ptr;
		ptr = frontPtr;
	}
initialize();
}

template <typename T>
Queue<T>:: ~Queue(){
	clear();
}
template <typename T>
const Queue<T> &Queue<T>:: operator = (const Queue<T> &s) throw (bad_alloc){
        if (&s != this){
                if(!empty()) clear();
                sz = s.sz;
                Node<T> *sptr = s.frontPtr;
                Node<T> *last = 0;
                while (sptr != 0){
                        if(last == 0)
                                frontPtr = last = new Node<T>(*sptr);

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
void Queue<T>::printInternal(){
	Node<T> *current = frontPtr;
	int i=0;
	cout<<"front: "<<frontPtr<<endl;
	while (current !=0){
		cout<<"Node: "<<i<<endl;
		cout<<"Address: "<<current <<endl;
		cout<<"contents: "<<current->getObject()<<endl;
		cout<<"next ptr: "<<current->getNextPtr()<<endl;
		current = current->getNextPtr();
		i++;
	}//while
}//printInternal()

#endif






