//Sohom Bhattacharya
//charNode.cpp
//  charNode(char input);---------> Constructor that sets the letter to the input character. 
//	void setCount(int a);---------> Sets the count to given input. 
//	void setLetter(char a);-------> Sets letter to given character input. 
//	void setNext(charNode* a);----> Sets next node given next input address.
//	int getCount();---------------> Returns count. 
//	char getLetter();-------------> Returns letter character. 
//	charNode* getNext();----------> Returns next charNode in linked list. 

#include "charNode.h"

charNode::charNode(char input)
{
	letter = input; 
	count = 1; 
	nextnode = NULL; 
}

//Pre-condition: a is an int
//Post-condition: a is an int
void charNode::setCount(int a)
{
	count = a; 
}

//Pre-condition: a is a char
//Post-condition: a is a char
void charNode::setLetter(char a)
{
	letter = a; 
}

//Pre-condition: a is a charNode pointer
//Post-condition: a is a charNode pointer
void charNode::setNext(charNode* a)
{
	nextnode = a; 
}	

//Pre-condition: count is of type int
//Post-condition: count is of type int
int charNode::getCount()
{
	return count;
}

//Pre-condition: letter is of type char
//Post-condition: letter is of type char
char charNode::getLetter()
{
	return letter;
}

//Pre-condition: nextnode is of type charNode pointer
//Post-condition: nextnode is of type charNode pointer
charNode* charNode::getNext()
{
	return nextnode;
}