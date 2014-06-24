//Sohom Bhattacharya
//hashNode.cpp
//	hashNode();--------------------> Constructor that sets the word to a blank string, count to 1, and nextnode to NULL. 
//	hashNode(string inputword);----> Constructor that sets the word to user input string, count to 1, and nextnode to NULL. 
//	void setCount(int a);----------> Sets the count to input value. 
//	void setWord(string a);--------> Sets word to input string. 
//	void setNext(hashNode* a);-----> Sets the nextnode to the address given. 
//	int getCount();----------------> Returns count. 
//	string getWord();--------------> Returns word string. 
//	hashNode* getNext();-----------> Returns the next node in the linked list. 

#include "hashNode.h"

hashNode::hashNode(string inputword)
{
	word = inputword; 
	count = 1; 
	nextnode = NULL; 
}


hashNode::hashNode()
{
	word = " ";
	count = 0; 
	nextnode = NULL; 


}

//Pre-condition: a is of type int
//Post-condition: a is of type int
void hashNode::setCount(int a)
{
count = a; 

}

//Pre-condition: a is of type string
//Post-condition: a is of type string
void hashNode::setWord(string a)
{
	word = a; 
}

//Pre-condition: a is of type hashNode pointer
//Post-condition: a is of type hashNode pointer
void hashNode::setNext(hashNode* a)
{
	nextnode = a; 
}

//Pre-condition: count is of type int
//Post-condition: count is of type int
int hashNode::getCount() 
{
	return count;
}

//Pre-condition: word is of type string
//Post-condition: word is of type string
string hashNode::getWord() 
{
	return word;
}

//Pre-condition: nextnode is of type hashNode pointer
//Post-condition: nextnode is of type hashNode pointer
hashNode* hashNode::getNext() 
{
	return nextnode; 
}