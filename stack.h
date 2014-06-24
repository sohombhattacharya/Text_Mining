//Sohom Bhattacharya
//stack.h
//Type pop--------------> Deletes the head and returns the value. 
//void push(Type b);----> Adds a node that holds Type b value onto the linked list as new head. 
//void printValues();---> Prints the values of the linked list. 
//bool isEmpty();-------> Checks if linked list is empty. 
//Stack();--------------> Constructor that sets head equal to NULL. 


#ifndef STACK
#define STACK
template <class Type>
class Stack
{


public: 
Type pop();
void push(Type b);
void printValues();
bool isEmpty();
Stack();

private: 
struct node
{

Type x;
node* ptr;
	
	node(Type input_x, node* ptrnode)
	{
	x = input_x;
	ptr = ptrnode; 
	}

};
node* head;

};
#endif