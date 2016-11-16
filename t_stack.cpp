#include "t_Stack.h"
#include <iostream>
#include <cassert>
using namespace std;

template<class T>
Stack<T>::Stack() //CTOR
{
	top = NULL; //top is NULL since there's nothing there
	size = 0; //size is zero
}

template<class T>
Stack<T>::~Stack() //DTOR
{
	while (!isEmpty()) //as long as Stack's not empty
	{
		popTop(); //pop the top
	}
}

template<class T>
void Stack<T>::pushTop(T d) //adds a new node to the top of the stack
{
	node<T> * n = new node<T>(d); //make ptr with size of new node
	
	if (isEmpty()) //if empty, set the top ptr to the new node
	{
		top = n; //top points to new node
	}

	else
	{
		//where next is down; or away from top;
		n->next = top; //newnode's next, or down, ptr points to top;
		top->prev = n; //top's prev, or up, ptr points to newnode
		top = n;//set the top ptr to newnode
	}

	size++;//since you're adding a node to the top
}

template<class T>
T Stack<T>::popTop() //removes the top node and returns the data store there
{
	assert(!isEmpty()); //don't pop an empty stack

	T d = top->data; //get the data from the top
	if (getSize() == 1) //this means this is the last node in the stack
	{
		delete top; //clears memory of top
		top = NULL; //so you know there's nothing left at top
	}
	else
	{
		top = top->next; //set top to the next node
		delete top->prev; //delete the previous node from the new top; aka the old top
		top->prev = NULL;//set PTR to NULL so it doesn't point in anywhere, since there's nothing there
	}
	size--; //since you're removing a node from the top
	return d; //return data
}


template<class T>
int Stack<T>::getSize() //returns the size of the stack: how many elements we have in there
{
	return size;
}

template<class T>
bool Stack<T>::isEmpty() //checks if the stack is empty; if the size is 0 than it's empty
{
	return (size == 0) ? true : false;
}

//overloading operator
template<class T>
void Stack<T>::operator +(T d) //overloading + to add an element to the top of the node
{
	node<T> * n = new node<T>(d); //make ptr with size of new node

	if (isEmpty()) //if empty, set the top ptr to the new node
	{
		top = n; //top points to new node
	}
	else
	{
		//where next is down; or away from top;
		n->next = top; //newnode's next, or down, ptr points to top;
		top->prev = n; //top's prev, or up, ptr points to newnode
		top = n;//set the top ptr to newnode
	}
	size++;//since you're adding a node to the top
}

template<class T>
T Stack<T>::operator -()//overloading - to remove an element from the top of the node and return the data there
{
	assert(!isEmpty()); //don't pop an empty stack

	T d = top->data; //get the data from the top
	if (getSize() == 1) //this means this is the last node in the stack
	{
		delete top; //clears memory of top
		top = NULL; //so you know there's nothing left at top
	}
	else
	{
		top = top->next; //set top to the next node
		delete top->prev; //delete the previous node from the new top; aka the old top
		top->prev = NULL;//set PTR to NULL so it doesn't point in anywhere, since there's nothing there
	}
	size--; //since you're removing a node from the top
	return d; //return data

}



//explicit instantiation

template class Stack <int>;
//template class Stack <int*>;
//template class Stack <float>;
//template class Stack <float*>;
//template class Stack <double>;
//template class Stack <double*>;
template class Stack <char>;
//template class Stack <char*>;
//template class Stack <std::string>;
