
#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

template <class T>
class ListNode {

		public:

			ListNode();
			ListNode(T d);
			~ListNode();

			T data;
			ListNode *next;
			ListNode *prev;
};

#endif //LISTNODE_H