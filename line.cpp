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


#include "line.h"
#include <ctype.h>
#include <cstdio>
#include <cstring>
#include <locale>

Line::Line()
{
	id = rand();
	pstr = new string;
	*pstr = "DUMMY";
	wordcount  =0;
}

Line::Line(string a)
{
	pstr = new string;
	*pstr = a;
	id = rand();
	wordcount = 0;
	trim();
}

Line::Line(string b, int value)
{
	pstr = new string;
	*pstr = b;
	id = value;
	wordcount = 0;
	trim();
}

Line::~Line()
{
 delete pstr;
}

//Pre-condition: a is of type string
//Post-condition:a is of type string
void Line::setString(string a)
{
	*pstr = a;
	trim();
}

//Pre-condition: c is of type char
//Post-condition: c is of type char
bool Line::myisspace(char c) 
{

	if( c == ' ' || c == '\n' || c == '\t' || c == '\r' )  
		return true;
	return false;
}

//Pre-condition: c is of type char 
//Post-condition: c is of type char
bool Line::myispunct( char c) {
	if( c == '.' || c == ';' || c == ','  || c ==  '!' || c == ';' || c == '?' || c == ':' )
		return true;
	return false;
}

//Pre-condition: {str == *pstr}
//Post-condition: {str != *pstr}
void Line::trim() 
{
	string str = *pstr;
	*pstr = trim( str );
}

//Pre-condition: {start == 0}
//Post-condition: {start >= 0}
string  Line::trim( string str ) 
{

	int start =0, end=str.length()-1;
	if ( start > end ) return "";
	
	// find the first beginning non space character

	while(   start < str.length() && myisspace(str[start] )  ) 
		start++;

	while(  end >0 && myisspace(str[end]) ) 
		end--;
	
	// now start and end have correct positions
	
	string newstr = str.substr( start, end+1-start);
	
	return newstr;
}

//Pre-condition: b is of type int
//Post-condition: b is of type int
void Line::setWordcount(int b)
{
	wordcount = b;
}

//Pre-condition: c is of type int
//Post-condition:
void Line::setCharcount(int c)
{
	charcount = c;
}

//Pre-condition: pstr is of type string pointer
//Post-condition: pstr is of type string pointer
string* Line::getString() const
{
	return pstr;
}


//Pre-condition: {count == 0}
//Post-condition: {count > -1}
int Line::getWordCount() 
{
	int count = 0;

	string str = *pstr;

	if ( wordcount != 0 )
		return wordcount;
	for (unsigned int i = 0; i < str.length(); i++)
	{ 
	
		if(  myisspace(str[i]) || myispunct(str[i]) ) {
			count++;
		}
	  
		while(  myisspace(str[i]) || myispunct(str[i]) ) {

			i++;
			if( i >= str.length())   // i may exceed length even here, so need to check here as well
				break;
		}
		
	}

	
	wordcount = count+1;
	return wordcount;

}

//Pre-condition: pstr->length() should be of type int
//Post-condition: pstr->length() should be of type int
int Line::getCharcount() const
{
	return pstr->length();
}


//Pre-condition: {count == 0}
//Post-condition: {count != 0}
string* Line::parseWords( ) 
{ 
	string str = *pstr;
	int wc = getWordCount();
	string * x = new string[wc ];
	int startWord = 0, endWord = 0;
	int count =0;
	for (unsigned int i = 0; i < str.length(); i++)
	{ 
	
		if(  myisspace(str[i]) || myispunct(str[i])  ) {
			endWord = i;
			
			*(x + count ) = str.substr(startWord,endWord-startWord);
			startWord = endWord; // and reset next start
			count++;
			
		}
	   
		while(  myisspace(str[i]) || myispunct(str[i]) ) {
			i++;
			if( i >= str.length())   // i may exceed length even here, so need to check here as well
				break;
		}
		
	}
	// the last one
	*(x + count ) = str.substr(startWord);
	return x;
	
}


//Pre-condition: {str == *pstr}
//Post-condition: {str == *pstr}
char *Line::parseChar( ) {
	string str = *pstr;
	char *x = new char[ str.length() + 1 ];
	
	memcpy( x, str.c_str(), str.length() );
	
	*(x + str.length() ) = '\0'; 

	return x;
}



//Pre-condition: {totalsize == 0}
//Post-condition: {totalsize > 0}
char *Line::parseChar( string  *stringarray , int no_strings) {
	
	int totalsize  = 0;
	
	for ( int i = 0; i< no_strings; i++ ) {  // number of strings
		totalsize  += (*(stringarray+i)).length();
	}
	
	
	
	char *allocated_storage = new char[ totalsize +1 ]; 
	
	
	char *x = allocated_storage;

	for ( int i = 0; i< no_strings; i++ ) {

		memcpy( x, (stringarray+i)->c_str(), (stringarray+i)->length());
		x += (*(stringarray+i)).length();

		
		
	}
	*( allocated_storage + totalsize  ) = '\0'; 
	return allocated_storage;
}


