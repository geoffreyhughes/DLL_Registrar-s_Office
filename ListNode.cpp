
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 4: Registrar's Office Simulation
*/


/*
	This source file contains the building block for our doubly-linked list. 
	Each ListNode stores data of any type <T>, as well as pointers linking it to the next ListNode and the previous ListNode.
	These ListNodes are linked together through their pointers, next and prev, to create the doubly-linked list ADT.
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "ListNode.h"

using namespace std;


/*
	ListNode Constructor; sets data to 0, and next and prev to NULL
*/
template <class T>	
ListNode<T>::ListNode() {

	data = 0;
	next = NULL;
	prev = NULL;
}


/*
	ListNode Constructor with parameter d (data); sets data to d (type <T>), and sets next and prev to NULL
*/
template <class T>	
ListNode<T>::ListNode(T d) {

	data = d;
	next = NULL;
	prev = NULL;
}


/*
	ListNode Destructor; When a ListNode reaches the end of its life...
*/
template <class T>	
ListNode<T>::~ListNode() {


}
