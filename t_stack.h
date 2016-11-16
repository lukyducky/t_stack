#ifndef _T_STACK_H
#define _T_STACK_H


#include "node.h"

template <class T>
class Stack{
private:
	node<T>* top; //PTR to keep track of the top
	int size; //tells us how many nodes we got in our stack

public:
	Stack(); //CTOR
	~Stack(); //DTOR

	//function placeholders; will be defined in the .cpp
	void pushTop(T d);
	T popTop();

	int getSize();
	bool isEmpty();

	void operator + (T d);
	T operator -();

	friend std::ostream& operator <<(std::ostream& os, Stack<T>& s) //overloading operator to print out vaules of our Stack.
	{
		int size = s.getSize(); //getting size of stack
		for (int i = 0; i < size; ++i) //looping through every element in stack
		{
			os <<s.popTop() << "; "; //printing with a ; to seperate elements; we can use os like cout to print things
			if (i != 0 && i % 10 == 0){ cout << endl; }//keeps it to 10 elements a line
		}
		return os; //return os
	}
	

};

#endif