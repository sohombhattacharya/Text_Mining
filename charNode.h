//Sohom Bhattacharya
//charNode.h
//  charNode(char input);---------> Constructor that sets the letter to the input character. 
//	void setCount(int a);---------> Sets the count to given input. 
//	void setLetter(char a);-------> Sets letter to given character input. 
//	void setNext(charNode* a);----> Sets next node given next input address.
//	int getCount();---------------> Returns count. 
//	char getLetter();-------------> Returns letter character. 
//	charNode* getNext();----------> Returns next charNode in linked list. 

#ifndef characternode
#define characternode
#include <iostream>
#include <string>
#include <cstdlib>


class charNode
{
public: 
	charNode(char input);
	void setCount(int a);
	void setLetter(char a);
	void setNext(charNode* a);
	int getCount();
	char getLetter();
	charNode* getNext();

private: 
	int count; 
	char letter; 
	charNode* nextnode;
};
#endif