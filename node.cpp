//Sohom Bhattacharya
//Node.cpp
//	Node(int x, char delimeter, Node* ptrnode);--> Constructor that sets the value, delimeter, and next node based on inputs. 
//	void setValue(int a);------------------------> Sets the value of node based on user input. 
//	void setDelim(char a);-----------------------> Sets the delim the node holds based on user input. 
//	void setNext(Node* a);-----------------------> Sets next node in linked list based on given address.
//	int getValue();------------------------------> Returns node value. 
//	int getDelim();------------------------------> Returns node delimeter. 
//	Node* getNext();-----------------------------> Returns next node in the linked list. 

#include "node.h"

Node::Node(int x, char delimeter, Node* ptrnode)
{
	value = x;
	nextnode = ptrnode;
	delim = delimeter;
}

//Pre-condition: a is an int
//Post-condition: a is an int
void Node::setValue(int a)
{

	value = a; 

}

//Pre-condition: a is an char
//Post-condition: a is an char
void Node::setDelim(char a)
{

	delim = a; 

}

//Pre-condition: a is a Node pointer
//Post-condition:a is a Node pointer
void Node::setNext(Node* a)
{
	nextnode = a; 

}

//Pre-condition: value is of type int
//Post-condition: value is of type int
int Node::getValue()
{
	return value; 
}
	
//Pre-condition: delim is of type char
//Post-condition: delim is of type char
char Node::getDelim()
{
	return delim; 
}
	
//Pre-condition: nextnode is of type Node pointer
//Post-condition: nextnode is of type Node pointer
Node* Node::getNext()
{
	return nextnode; 
}