//Sohom Bhattacharya
//Node.h
//	Node(int x, char delimeter, Node* ptrnode);--> Constructor that sets the value, delimeter, and next node based on inputs. 
//	void setValue(int a);------------------------> Sets the value of node based on user input. 
//	void setDelim(char a);-----------------------> Sets the delim the node holds based on user input. 
//	void setNext(Node* a);-----------------------> Sets next node in linked list based on given address.
//	int getValue();------------------------------> Returns node value. 
//	int getDelim();------------------------------> Returns node delimeter. 
//	Node* getNext();-----------------------------> Returns next node in the linked list. 

#ifndef nodes
#define nodes

class Node
{

public: 
	Node(int x, char delimeter, Node* ptrnode);
	void setValue(int a);
	void setDelim(char a);
	void setNext(Node* a);
	int getValue();
	char getDelim();
	Node* getNext();

private: 
	int value;
	char delim;
	Node* nextnode;
};
#endif