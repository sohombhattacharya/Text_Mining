//Sohom Bhattacharya
//hashNode.h
//	hashNode();--------------------> Constructor that sets the word to a blank string, count to 1, and nextnode to NULL. 
//	hashNode(string inputword);----> Constructor that sets the word to user input string, count to 1, and nextnode to NULL. 
//	void setCount(int a);----------> Sets the count to input value. 
//	void setWord(string a);--------> Sets word to input string. 
//	void setNext(hashNode* a);-----> Sets the nextnode to the address given. 
//	int getCount();----------------> Returns count. 
//	string getWord();--------------> Returns word string. 
//	hashNode* getNext();-----------> Returns the next node in the linked list. 

#ifndef Hashnode
#define Hashnode
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


class hashNode
{
public: 
	hashNode();
	hashNode(string inputword);
	void setCount(int a);
	void setWord(string a);
	void setNext(hashNode* a);
	int getCount();
	string getWord();
	hashNode* getNext(); 

private:
	int count; 
	string word; 
	hashNode* nextnode;
};
#endif 

