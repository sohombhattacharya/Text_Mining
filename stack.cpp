//Sohom Bhattacharya
//stack.cpp
//Type pop--------------> Deletes the head and returns the value. 
//void push(Type b);----> Adds a node that holds Type b value onto the linked list as new head. 
//void printValues();---> Prints the values of the linked list. 
//bool isEmpty();-------> Checks if linked list is empty. 
//Stack();-------------->
#include "stack.h"

template <class Type>
Stack<Type>::Stack()
{
head = NULL ;
}

//Pre-condition: {head != NULL}
//Post-condition: {head == t}
template <class Type>
Type Stack<Type>::pop()
{
Type a = head->x;
node* t = head->ptr;
delete head;
head = t;
return a;
}

//Pre-condition: head must be node pointer
//Post-condition: head must be node pointer
template <class Type>
bool Stack<Type>::isEmpty()
{
	if ( head == NULL ) return true;
	return false;
}

//Pre-condition: {head != NULL}
//Post-condition: {head != NULL}
template <class Type>
void Stack<Type>::push(Type b) 
{
head = new node(b, head); 
}

//Pre-condition: {head != NULL}
//Post-condition: {head != NULL}
template <class Type>
void Stack<Type>::printValues()
{

while (head->ptr != NULL)
{
cout << head->x << " ";
head = head->ptr;
}

}