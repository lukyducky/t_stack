#ifndef _NODE_H
#define _NODE_H

#include <iostream>

template<class T>
class node{
public:
	T data;
	node<T> *next;
	node<T> *prev;

	node(){
		data = 0;
		next = prev = 0;
	}

	node(T d){
		data = d; 
		next = prev = 0;
	}

};



#endif