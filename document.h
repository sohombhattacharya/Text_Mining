//Sohom Bhattacharya
//document.h
	//Document(); ----------------------------------> Default constructor that sets the wordcount to 0.
	//Document(string c);  -------------------------> Constructor that takes in a string as a parameter for the name of the document.
	//Document(string a, int value); ---------------> Constructor that takes in a string and id number for the name of the document and it's id.

	//
	//void setLinecount(int a); --------------------> Takes in an int value as parameter and sets the line count equal to it.
	//void setWordcount(int b);---------------------> Takes in an int value as parameter and sets the word count equal to it.
	//void setStringname(string c);-----------------> Takes in a string as parameter and sets the name of the document equal to the input.
	//int getLinecount() const;---------------------> Returns the line count of the document.
	//int getWordcount();---------------------------> Returns the word count if it has been computed already. If not, it will compute the word count and then return it.  
	//Line* getArray()  const;----------------------> Returns an array of lines of the document.
	//string getString() const;---------------------> Returns the name of the document.
	//int getCharcount(); --------------------------> Counts the characters per line and returns an array of all the characters in the document. 
	//
	//// other methods
	//void loadDocument(string fileLocation);-------> Takes in a string as parameter for the name of the document, and loads the document by computing the linecount and wordcount. 
	//void outputDocument(string fileLocation);-----> Takes in a file location as string as parameter and outputs the document's text to that location. 
	//string* parseWords();-------------------------> Takes all the words in the document and places them into an array of strings and returns a pointer to the array of strings. 
	//char* parseChar();----------------------------> Takes all the characters in the documents and places them int an array of char and returns a pointer to the array of char. 
	//void resize();--------------------------------> Increases the size of the array of lines if there is not enough space in it. Used in loadDocument. 
	//void lineLengths(); --------------------------> Creates a linked list for lines by creating Nodes with each Node's value equal to the word count of each line and Node's delimeter equal to the line's delimeter. 
	//int reverseCompare(Document d2);--------------> Takes in a document as parameter and compares them in reverse and returns the number of words that are different. 
	//void createWordHashtable();-------------------> Creates a hash table of all the words in the document.
	//void createCharHashTable();-------------------> Creates a hash table of all the characters in the document. 
	//int hash(const char* v);----------------------> Hash function for the hash table. 
	//int hashChar(char v);-------------------------> Hash function for the characters. //NEED TO FIX THIS FIND OUT DIFFERENT BETWEEN BOTH HASH FUNCTIONS 
	//void sortWordHashTable();---------------------> Sorts the hash table of words based on counts. 
	//void sortCharHashTable();---------------------> Sorts the hash table of characters based on counts; 
	//void createCharSortedArray();-----------------> Creates a sorted array of all the characters in the document. 
	//void createWordSortedArray();-----------------> Creates a sorted array of all the words in the document. 
	//int* getTopKWordFreq(int k);------------------> Creates an array of ints that are frequencies for the top K, based on user input, words in the document from the hashtable and returns a pointer to the array of ints. 
	//int* getBottomKWordFreq(int k);---------------> Creates an array of ints that are frequencies for the bottom K, based on user input, words in the document from the hashtable and returns a pointer to the array of ints. 
	//char* characterOffSet(int a);-----------------> Creates a character array for every other (a), user input, index in the original character array of the document. Then returns a pointer to the array of characters. 
	//int* offsetCharFreq(char* offsetarr, int l);--> Takes in the character offset array and its length as parameters, sorts it, and returns a pointer to an array of ints of frequencies of the characters. 
	//void allWordCountSortMethod();----------------> Creates a sorted array of the counts of all the words in the document. 
	//int* getTopKWordsSortMethod(int k);-----------> Creates an array of ints that are frequencies for the top K, based on user input, words in the document through sorting and returns a pointer to the array of ints. 
	//int* getBottomKWordsSortMethod(int k);--------> Creates an array of ints that are frequencies for the bottom K, based on user input, words in the document through sorting and returns a pointer to the array of ints. 
	//int* allCharFreq();---------------------------> Returns a pointer to the array of ints that are frequencies for all the characters in the document. 
	//char* caesarCipherOffset(char offset);--------> Takes in a character as offset parameter, and adds it to each character in the document and returns that new pointer to array of characters. 
	//char* vigenereCipher(string key);-------------> Takes in a string as key parameter, and adds each letter of the key to each character in the document and repeats until the end of the document and returns a pointer to the array of new characters. 
	//void decryptCaesar(char offset);--------------> Takes in a char for the offset and decrypts the encrypted caesar cipher. 
	//void decryptVigenere(string key);-------------> Takes in a string for the key and decrypts the encrypted vigenere cipher. 
	//double* wordTrace(string* words, int count);--> Takes in a pointer to an array of strings and the count for it as parameters, and traces from the beginning and the end of the document the first and last time each word is found. Then returns x and y values of all the words in the form of one pointer to an array of doubles. 




#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <list>
#include "line.h"
#include "stack.h"
#include "node.h"
#include "hashNode.h"
#include "Metrics.h"
#include "charNode.h"



using namespace std;


class Document
{
public:
	int id;
	
	Document();
	Document(string c);  
	Document(string a, int value); 

	
	void setLinecount(int a);
	void setWordcount(int b);
	void setStringname(string c);
	int getLinecount() const;
	int getWordcount();
	Line* getArray()  const;
	string getString() const;
	int getCharcount(); 
	
	// other methods
	void loadDocument(string filename);
	void outputDocument(string filename);
	string* parseWords() ;
	char* parseChar();
	void resize();
	void lineLengths(); 
	int reverseCompare(Document d2);
	void createWordHashtable();
	void createCharHashTable();
	int hash(const char* v);
	int hashChar(char v);
	void sortWordHashTable();
	void sortCharHashTable();
	void createCharSortedArray();
	void createWordSortedArray();
	int* getTopKWordFreq(int k);
	int* getBottomKWordFreq(int k);
	char* characterOffSet(int a);
	int characterOffSetSize(int offset);
	int* offsetCharFreq(char* offsetarr, int l);
	void allWordCountSortMethod();
	int* getTopKWordsSortMethod(int k);
	int* getBottomKWordsSortMethod(int k);
	int* allCharFreq();
	void caesarCipherOffset(char offset);
	void vigenereCipher(string key);
	void decryptCaesar(char offset);
	void decryptVigenere(string key);
	double* wordTrace(string* words, int count);
	
	
private:
	int Linecount;
	int wordcount;
	Line* arrayofLines;
	int size;
	string name;
	static const int hashTablesize = 10000;
	hashNode** hashtable;
	charNode** charHashTable;
	Node* head;
	int* topKWordFreqp;
	int* bottomKWordFreqp;
	int* topKCharFreqp; 
	int* bottomKCharFreqp; 
	int* allWordCountArrayp; 
	int* allCharCountArrayp;
	char* caesarCipherTextp; 
	char* vigenereCipherTextp;
	int charCount; 


};
