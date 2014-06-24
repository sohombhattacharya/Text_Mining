// Sohom Bhattacharya
// line.cpp
    //Line();------------------------------------------------------> Default constructor that sets id to random, sets word count to 0, and creates a string name for the line called "DUMMY" 
	//Line(string a);----------------------------------------------> Constructor that takes in a string as parameter and sets the name of the line equal to it. Also sets id to random, and word count to 0, and calls trim.  
	//Line(string b, int value);-----------------------------------> Constructor that takes in a string for the name and int value for the wordcount as parameters. Also sets id to random, word count to 0, and calls trim. 
	//~Line();-----------------------------------------------------> Deconstructor that deletes string name. 

	
	//void setString(string a);------------------------------------> Takes in a string parameter and sets the name of the line equal to it. 
	//void setWordcount(int b);------------------------------------> Takes in an int parameter and sets the word count of the line equal to it. 
	//void setCharcount(int c);------------------------------------> Takes in an int parameter and sets the character count of the line equal to it. 
	//string* getString() const;-----------------------------------> Returns the name of the line. 
	//int getWordCount();------------------------------------------> Returns the word count of the line.  
	//int getCharcount() const;------------------------------------> Returns the character count of the line. 
	//string* parseWords();----------------------------------------> Returns a pointer to an array of strings of all the words in the line. 
	//char*  parseChar();------------------------------------------> Returns a pointer to an array of char of all the characters in the line. 
	//void trim();-------------------------------------------------> Deletes all the spaces from inside of line. 
	//bool Line::myisspace( char c);-------------------------------> Checks for spaces. Returns true or false. 
	//bool Line::myispunct( char c);-------------------------------> Checks for punctuation. Returns true or false. 
#ifndef lines
#define lines
#include <iostream>
// Sohom Bhattacharya
// line.cpp
    //Line();------------------------------------------------------> Default constructor that sets id to random, sets word count to 0, and creates a string name for the line called "DUMMY" 
	//Line(string a);----------------------------------------------> Constructor that takes in a string as parameter and sets the name of the line equal to it. Also sets id to random, and word count to 0, and calls trim.  
	//Line(string b, int value);-----------------------------------> Constructor that takes in a string for the name and int value for the wordcount as parameters. Also sets id to random, word count to 0, and calls trim. 
	//~Line();-----------------------------------------------------> Deconstructor that deletes string name. 

	
	//void setString(string a);------------------------------------> Takes in a string parameter and sets the name of the line equal to it. 
	//void setWordcount(int b);------------------------------------> Takes in an int parameter and sets the word count of the line equal to it. 
	//void setCharcount(int c);------------------------------------> Takes in an int parameter and sets the character count of the line equal to it. 
	//string* getString() const;-----------------------------------> Returns the name of the line. 
	//int getWordCount();------------------------------------------> Returns the word count of the line.  
	//int getCharcount() const;------------------------------------> Returns the character count of the line. 
	//string* parseWords();----------------------------------------> Returns a pointer to an array of strings of all the words in the line. 
	//char*  parseChar();------------------------------------------> Returns a pointer to an array of char of all the characters in the line. 
	//void trim();-------------------------------------------------> Deletes all the spaces from inside of line. 
	//bool Line::myisspace( char c);-------------------------------> Checks for spaces. Returns true or false. 
	//bool Line::myispunct( char c);-------------------------------> Checks for punctuation. Returns true or false. 

#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Line
{

public:
	Line();
	Line(string a);
	Line(string b, int value);
	~Line();

	int id; // index num
	void setString(string a);
	void setWordcount(int b);
	void setCharcount(int c);
	string* getString() const;
	int getWordCount() ;  // can not be const , because u are changing wordcount
	int getCharcount() const;
	string* parseWords();
	char*  parseChar();
	void trim();
	string trim( string s );
	char *parseChar( string  stringarray [] , int no_strings);
	bool Line::myisspace( char c);
	bool Line::myispunct( char c);



private:
	string *pstr;
	int wordcount;
	int charcount;

};
#endif 