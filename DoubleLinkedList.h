#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "ListNode.h"
#include "ListNode.cpp"

using namespace std;



template <class T>
class List {


	virtual void insertFront(T data) = 0;
	virtual void insertBack(T data) = 0;
	virtual T removeFront() = 0;
	virtual T removeBack() = 0;
	virtual T peek() = 0;

	virtual bool contains(T value) = 0;
	virtual T remove(T key) = 0;
	virtual T deletePos(int pos) = 0;
	virtual unsigned int getSize() = 0;
	virtual bool isEmpty() = 0;

	virtual int find(T data) = 0;


};


template <class T>
class DoubleLinkedList : List<T>

 {

	private:

		ListNode<T> *front;
		ListNode<T> *back;
		unsigned int size;

	public:

		DoubleLinkedList();
		~DoubleLinkedList();

		virtual void insertFront(T data);
		virtual void insertBack(T data);
		virtual T removeFront();
		virtual T removeBack();
		virtual T peek();

		virtual bool contains(T value);
		virtual T remove(T key);
		virtual T deletePos(int pos);
		virtual unsigned int getSize();
		virtual bool isEmpty();

		virtual int find(T data);
		
};


#endif //DOUBLELINKEDLIST_H