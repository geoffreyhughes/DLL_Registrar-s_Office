
/*
Geoffrey Hughes
002306123
ghughes@chapman.edu
CPSC 350-02
Assignment 4: Registrar's Office Simulation
*/


/*
	This source file builds a Doubly-Linked list ADT using the ListNode class.
	This DLL can store any data type. <T>
	The functions we use to implement the Queue class are here: insertBack(data), removeFront(), and peek()
	But all the other functions expected in a DLL are implemented here too. 
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "DoubleLinkedList.h"


using namespace std;


/*
	DLL Constructor, defines size, and dynamically creates and allocates a front and back ListNode of type <T>
*/
template <class T>	
DoubleLinkedList<T>::DoubleLinkedList() {


	size = 0;

	front = new ListNode<T>();
	back = new ListNode<T>();
}


/*
	DLL Destructor, sets next and prev to NULL so that the ListNode can be deleted properly
*/
template <class T>	
DoubleLinkedList<T>::~DoubleLinkedList() {

	if (front != NULL) {

		front->next = NULL;
		front->prev = NULL;
	}

	if (back != NULL) {

		back->next = NULL;
		back->prev = NULL;
	}
}


/*
	Returns nothing; inserts data (taken as a parameter) of type <T> into the front of the DLL
*/
template <class T>
void DoubleLinkedList<T>::insertFront(T data) {

	ListNode<T>* node = new ListNode<T>(data);

	if (isEmpty()) 
	{
		back = node;
	}

	else 
	{
		front->prev = node;
		node->next = front;
	}

	front = node;
	size++;
}


/*
	USED IN QUEUE: Returns nothing; inserts data (taken as a parameter) of type <T> into the back of the DLL
*/
template <class T>	
void DoubleLinkedList<T>::insertBack(T data) {

	ListNode<T>* node = new ListNode<T>(data);
	
	if (isEmpty())
	{
		front = node;
	}

	else
	{
		back->next = node;
		node->prev = back;
	}

	back = node;
	size++;
}


/*
	USED IN QUEUE: Returns type <T>; removes the ListNode from the front of the DLL and returns its data
*/
template <class T>	
T DoubleLinkedList<T>::removeFront() 
{
	if (isEmpty()) {

		cout << "ERROR: Trying to remove from empty list" << endl;
	}

	if (front->next == NULL) {
		back = NULL;

	}
	else {
		front->next->prev = NULL;
	}

	T temp = front->data;
	ListNode<T>* ft = front;
	front = front->next;
	ft->next = NULL;
	delete ft;
	--size;

	return temp;
}


/*
	Returns type <T>; removes the ListNode from the back of the DLL and returns its data
*/
template <class T>	
T DoubleLinkedList<T>::removeBack() 
{

	if (isEmpty()) {

		cout << "ERROR: Trying to remove from empty list" << endl;
	}

	if (back->prev == NULL) {
		front = NULL;

	}
	else {
		back->prev->next = NULL;
	}

	T temp = back->data;
	ListNode<T>* bk = back;
	back = back->prev;
	bk->prev = NULL;
	delete bk;
	--size;

	return temp;
}


/*
	USED IN QUEUE: Returns type <T>; does not modify the DLL, only returns front's data
*/
template <class T>
T DoubleLinkedList<T>::peek()
{
	return front->data;
}


/*
	Returns true or false (bool); Scans the DLL and finds whether it contains a ListNode with data of type T that matches the T parameter
*/
template <class T>
bool DoubleLinkedList<T>::contains(T value) {

	bool doesContain = false;

	/*
	ListNode<T>* curr = front;
	while (curr != NULL) {

		if (curr->data == value) {
			doesContain = true;
		}

		curr = curr->next;
	}
	*/

	return doesContain;
}


/*
	Returns type <T>; finds the position of data of type <T> passed in as a parameter
	If it finds the ListNode with that data of type <T>, it deletes that ListNode, and returns its data
*/
template <class T>
T DoubleLinkedList<T>::remove(T key) {

	// Check to make sure is not isEmpty
	if (isEmpty())
	{
		cout << "Error: Calling remove(int key), but List is empty" << endl;
	}

	int pos = find(key);
	deletePos(pos);

	return key;
}


/*
	Returns type <T>; In this DLL, if the front is index 0, and back is index n,
	this function finds ListNode of index "pos" (passed as a parameter), deletes it, and returns its data
*/
template <class T>	
T DoubleLinkedList<T>::deletePos(int pos) {

	// Check to make sure is not isEmpty
	if (isEmpty())
	{
		cout << "Error: Calling deletePos(int pos) at index " << pos << ", but List is empty" << endl;
	}

	int index = 0;
	ListNode<T>* curr = front;
	ListNode<T>* prev = front;

	// Traverse my list and update pointers accordingly
	while (index != pos) {

		prev = curr;
		curr = curr->next;
		++index;
	}

	// Make check to NULL

	prev->next = curr->next;
	curr->next = NULL;
	T temp = curr->data;
	delete curr;
	size--;

	return temp;

}


/*
	Returns an integer; Simple get function to return the number of ListNodes currently in the DLL
*/
template <class T>
unsigned int DoubleLinkedList<T>::getSize() {

	return size;
}


/*
	Returns true or false (bool); Returns true if the DLL is empty, and returns false otherwise
*/
template <class T>
bool DoubleLinkedList<T>::isEmpty() {

	if (size <= 0) 
	{
		return true;
	}

	else 
	{
		return false;
	}
}


/*
	Returns an integer (representing the position in the DLL); Finding data in the front ListNode would return 0
*/
template <class T>	
int DoubleLinkedList<T>::find(T data) {

	int index = -1;
	ListNode<T>* curr = front;
	/*
	while (curr != NULL) {

		++index;
		if (curr->data == data) {
			break;
		}
		else {
			curr = curr->next;
		}
	}

	if (curr == NULL) {
		index = -1;
	}
	*/

	return index;
}


