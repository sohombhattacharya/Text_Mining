//Sohom Bhattacharya
//document.cpp
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



#include "document.h"
#include "const.h"
#include "stack.cpp"
#include "Metrics.cpp"

#include <string>
using namespace std;


Document::Document()
{
wordcount = 0; 
}


Document::Document(string c){
	name = c;
	id = rand();
	wordcount = 0;
}

Document::Document(string a, int value){
	name = a;
	id = value;
	wordcount = 0;

}


//Pre-condition: a is an int
//Post-condition: a remains an int
void Document::setLinecount(int a){

	Linecount = a;

}

//Pre-condition: b is an int
//Post-condition: b remains an int
void Document::setWordcount(int b){

	wordcount = b;

}

//Pre-condition: c is a string
//Post-condition: c remains a string
void Document::setStringname(string c){

	name = c;

}

//Pre-condition: Linecount is an int
//Post-condition: Linecount is an int
int Document::getLinecount() const{

	return Linecount;

}

//Pre-condition: {sum == 0}
//Post-condition: {sum >= 0}
int Document::getWordcount() {

	int sum = 0;

	if (wordcount == 0) {

		for ( int i = 0; i< Linecount; i++) {
			// FIX 20140503
			sum += (arrayofLines+i)->getWordCount();
		}

		wordcount = sum;
		
		return wordcount;

	}
	else
	{
		
		return wordcount;
	}
}


//Pre-condition: arrayofLines is a Line* 
//Post-condition: arrayofLines is a Line*
Line* Document::getArray() const{
	return arrayofLines;
}

//Pre-condition: name is a string
//Post-condition: name is a string
string Document::getString() const{
	return name;
}


//Pre-condition: {i == 0}
//Post-condition: {i < size/2}
void Document::resize() 
{
    
	Line* newArrp = new Line[2*size];
    for ( int i =0; i< size ; i++ ) {
		
		string *sp = (arrayofLines+i)->getString();
		Line *tmp = newArrp + i;
		tmp->setString( *sp);
	}

    
    size = 2*size;
    delete [] arrayofLines;
    arrayofLines = newArrp;
}

//Pre-condition: {i == 0}
//Post-condition: {i < Linecount}
void Document::outputDocument(string filename) 
{
	ofstream ofs (filename.c_str());
	if ( !ofs.is_open() ) {
		cout << "Could not open " << filename << endl;
		return;
	}
	for ( int i = 0; i< Linecount; i++ ) 
	{
		string* sp = (arrayofLines + i )->getString();
		ofs<< *sp << endl;
	}
	ofs.close();
}


//Pre-condition: {counter == 0}
//Post-condition: {counter != 0}
void Document::loadDocument(string  filename){
	ifstream ifs (filename.c_str()); 
	string multi_sentence, sentence;
	string temp;
	string textdoc;
	int counter = 0;
	size = 1000;
	
	if ( !ifs.is_open() ) {
		Linecount = 0;
		cout << "Could not open " << filename << endl;
		return;
	}
	
	arrayofLines = new Line[size];

	while(getline(ifs, multi_sentence, '.')) { 

		int len = multi_sentence.length();
		int start=0,i = 0;
		for (  i = 0; i< len ; i++ ) {
			char c = multi_sentence.at( i);
			if(  c == ','  || c ==  '!' || c == ';' || c == '?' || c == ':' )
			{
				sentence = multi_sentence.substr( start, i-start );     // sub string start pos, length, 
				counter++;												// this will include the delimiter
				if( counter > size) {
					resize();
				}
				Line *tmp = arrayofLines + counter-1;
				tmp->setString( sentence );
				id = counter;
				start=i+1;
			}
		}
		// finally the last sgment, it has to end with .
		sentence = multi_sentence.substr( start, i-start );     // sub string start pos, length, 
		counter++;												// this will include the delimiter
		if( counter > size) {
			resize();
		}
		Line *tmp = arrayofLines + counter-1;
		tmp->setString( sentence );
		id = counter;
		// end of last segment
	}
	Linecount  = counter;


}

//Pre-condition: {counter == 0}
//Post-condition:{counter > 0}
string* Document::parseWords() 
{
	int wc = getWordcount();
	int counter =0;
	string *parsedOutputp = new string[ wc ];   // create a storage enough to hold all the  words in the entire doc
	for ( int linenum = 0; linenum< Linecount; linenum++ ) 
	{  // scan each line at a time
		string* sp = (arrayofLines + linenum )->parseWords();
		int wcInLine = (arrayofLines + linenum )->getWordCount();
		for ( int word_num = 0; word_num < wcInLine; word_num ++) 
		{                                                             
			*(parsedOutputp + counter) = *(sp + word_num );          
			counter++;
		}
		delete [] sp; 
	}
	return parsedOutputp;
}

//Pre-condition: {Linecount > 0}
//Post-condition: {Linecount > 0}
int Document::getCharcount() 
{
	int counter=0;
	for ( int linenum = 0; linenum< Linecount; linenum++ ) {  // scan each line at a time
		counter += (arrayofLines + linenum )->getCharcount();
	}
	return counter;
}

//Pre-condition: {wc != 0}
//Post-condition: {wc != 0}
char* Document::parseChar() {

	string* alltheWordsInDocp = parseWords();
	
	int wc = getWordcount();
	Line x;
	char *p =  x.parseChar( alltheWordsInDocp, getWordcount());
	delete [] alltheWordsInDocp;  
	return p;

}

//Pre-condition: {temp == NULL}
//Post-condition: {temp != NULL}
void Document::lineLengths()
{

	Node* temp = new Node(0,0,0);
	for (int i = 0; i < Linecount; i++)
	{
	temp = head->getNext();
	head->setValue((arrayofLines + i)->getWordCount());
	
	int lineCharcount = (arrayofLines +i)->getCharcount(); 
	char* sp = (arrayofLines+i)->parseChar();
	head->setDelim(sp[lineCharcount - 1]);
	
	head = head->getNext();
	}

	head->setNext(NULL);
}


//Pre-condition: {d1wordcount != 0}
//Post-condition: {d1wordcount != 0}
int Document::reverseCompare(Document document2)
{
	string* d1wordsp = parseWords();
	Stack<string> d1wordStack;
	int d1wordcount = getWordcount();
	
		for (int i = 0; i < d1wordcount; i++)
		{
			d1wordStack.push(d1wordsp[i]);
	
		}

	int counter = 0; 
	string* d2wordsp = document2.parseWords();
	int d2wordcount = document2.getWordcount();

	Line x;
	int i = 0;
	int breakindex=-1;
	for ( i = d2wordcount-1; i >= 0; i--)   
	{
		if ( !d1wordStack.isEmpty() ) 
		{
			string popped = d1wordStack.pop();
			string d1 =x.trim( popped );
			string d2 =x.trim( d2wordsp[i] );

			if (d1 != d2)
				counter++;
		} 
		else
		{
			breakindex = i;
			i = -1;
		}
	}
	if ( !d1wordStack.isEmpty() ) // excess in stack
		counter++;

	if ( breakindex >=0  ) // excess in array
		counter += (breakindex +1 );

	return counter; 
}

//Pre-condition: {h == 0}
//Post-condition: {h > 0}
int Document::hash(const char* v)
{
	int h = 0; 
	int a = 127; 
	int max = 96;
	for (; *v != '\0'; v++)
	h = (a*h + *v)%max;

	return h;


}

//Pre-condition: {h == 0}
//Post-condition: {h > 0}
int Document::hashChar(char v)
{
	int h = 0; 
	int a = 127; 
	int max = 61;
	for (; v != '\0'; v++)
	h = (a*h + v)%max;

	return h;

}

//Pre-condition: {i == 0}
//Post-condition: {i != 0}
void Document::createCharHashTable()
{
	charHashTable = new charNode*[hashTablesize];

	// initialize the whole table to NULL, each slot contains an empty linked list
	for (int i = 0; i < hashTablesize; i++)
		charHashTable[i] = NULL;

	char* lettersp = parseChar();
	int charcount = strlen(lettersp);
	for ( int i = 0; i < charcount ; i++ ) 
	{
		char letter = lettersp[i];
		int hashCode = hashChar(letter);

		// hashCode gives the slot to put that word in 
		// it hashcode  exceeds array capacity or < 0 put that word in the last slot
		if ( hashCode < 0 || hashCode >= hashTablesize )
			hashCode = hashTablesize -1;

		// This slot has nothing yet, create the first node
		if ( hashtable[hashCode ] == NULL ) 
		{ 
			charHashTable[ hashCode ] = new charNode(letter);
		} 
		else 
		{
			// COLLISSION case : this slot already has other items , ie either 
			// a previous word generated the same hashCode OR the same word 
			// must have come before.
			// if the same exact word came before just increment the count
			// otherwise need to add this word in the linked list in this slot
			//
			charNode* headp = charHashTable[ hashCode ];
			bool foundLetter = false;
			int counter = 1; 
			while ( headp->getNext() != NULL ) 
			{
				if ( headp->getLetter() == letter ) 
				{  // ie the same word came before
					counter++;
					headp->setCount(counter);
					foundLetter= true;
					break;  // nothing else to do
				}
				headp=headp->getNext();
			}
			
			if ( !foundLetter ) // if exact word was found and count was incremented only, there is no need to add a new node to the list
				{
					charNode* newnode = new charNode(letter);
					headp->setNext(newnode);
				
				}
			}
	}

}

//Pre-condition: {i == 0}
//Post-condition: {i < wordcount}
void Document::createWordHashtable()
{

	hashtable = new hashNode*[hashTablesize];

	// initialize the whole table to NULL, each slot contains an empty linked list
	
	for (int i = 0; i < hashTablesize; i++)
		hashtable[i] = NULL; 

	string* wordsp = parseWords();
	int wordcount = getWordcount();
	for ( int i = 0; i< wordcount ; i++ ) 
	{
		string word = wordsp[i];
		int hashCode = hash(word.c_str());

		// hashCode gives the slot to put that word in 
		// it hashcode  exceeds array capacity or < 0 put that word in the last slot
		if ( hashCode < 0 || hashCode >= hashTablesize )
			hashCode = hashTablesize -1;

		// This slot has nothing yet, create the first node
		if ( hashtable[hashCode ] == NULL ) 
		{ 
			hashtable[ hashCode ] = new hashNode( word);
		} 
		else 
		{
			// COLLISSION case : this slot already has other items , ie either 
			// a previous word generated the same hashCode OR the same word 
			// must have come before.
			// if the same exact word came before just increment the count
			// otherwise need to add this word in the linked list in this slot
			//
			hashNode *headp = hashtable[ hashCode ];
			bool foundWord = false;
			int counter = 1;
			while ( headp->getNext() != NULL ) 
			{
				if ( headp->getWord().compare( word ) == 0 ) 
				{  // ie the same word came before
					counter++;
					headp->setCount(counter);
					foundWord= true;
					break;  // nothing else to do
				}
				headp=headp->getNext();
			}
			
			if ( !foundWord ) // if exact word was found and count was incremented only, there is no need to add a new node to the list
			{
				hashNode* newnode = new hashNode(word);
				headp->setNext(newnode);
			}

		}
	}

	
}

//Pre-condition: {i == 0}
//Post-condition: {i < hashTablesize}
void Document::sortWordHashTable()
{
	for (int i = 0; i < hashTablesize; i++)
	{
		if (hashtable[i] != NULL)
		{
			Metrics<int> a;
			
			a.sortLinkedList(hashtable[i]);
		}
	}

}

//Pre-condition: {i == 0}
//Post-condition: {i < hashTablesize}
void Document::sortCharHashTable()
{

	for (int i = 0; i < hashTablesize; i++)
	{
		if (charHashTable[i] != NULL)
		{
		Metrics<int> a; 
		a.charSortLinkedList(charHashTable[i]);
		}
	
	
	}

}

//Pre-condition: {i == 0}
//Post-condition: {i < stringcount}
void Document::allWordCountSortMethod()
{

	string* unsortedp = parseWords();
	int stringcount = getWordcount();
	string *stringarray = new string[ stringcount];

	Metrics<string> a;
	a.mergeSort(unsortedp,stringarray, 0 , stringcount);
	
	allWordCountArrayp = new int[stringcount];
	int counter = 0; 

	int i = 0;
	for (i = 0; i < stringcount; i++)
		allWordCountArrayp[i] = 0;
	i=0;
	string prevstring = stringarray[0];
	for (int k = 0; k < stringcount; k++)
	{
		if(  prevstring == stringarray[k] )
			counter++;
		else 
		{
			if ( i < stringcount ) 
			{
				allWordCountArrayp[i] = counter;
				counter = 0;	
				i++;
			}
			else
				cout << "No of characters exceeded " << stringcount << endl;
		}
		prevstring = stringarray[k];
	}

	allWordCountArrayp[i] = -1;


}

//Pre-condition: {length == 0}
//Post-condition: {length < wc}
int* Document::getTopKWordsSortMethod(int k)
{
	int length = 0; 
	int wc = getWordcount(); 
	for (int i = 0; i < wc; i++)
	{
		if (allWordCountArrayp[i] == -1)
			i = wc; 

		else
			length++;
							
	}
	
	Metrics<int> a;
	a.insertionSort(allWordCountArrayp, length);

	topKWordFreqp = new int[k];


	int l = length - 1; 
	for (int i = 0; i < k; i++, l--)
	{
		topKWordFreqp[i] = allWordCountArrayp[l];
	}
	
	return topKWordFreqp; 


}

//Pre-condition: {length == 0}
//Post-condition: {length < getWordcount()}
int* Document::getBottomKWordsSortMethod(int k)
{

	int length = 0; 
	for (int i = 0; i < getWordcount(); i++)
	{
		int test = allWordCountArrayp[i];
		
		if (test == -1)
			i = getWordcount(); 

		else
			length++;
							
	}
	
	Metrics<int> a;
	a.insertionSort(allWordCountArrayp, length);

	bottomKWordFreqp = new int[k];


	
	for (int i = 0; i < k; i++)
	{
		bottomKWordFreqp[i] = allWordCountArrayp[i];
	}
	
	return bottomKWordFreqp;


}

//Pre-condition: {l == getWordcount() - 1}
//Post-condition: {l < (getWordcount() - 1}
int* Document::getTopKWordFreq(int k)
{

	topKWordFreqp = new int[k];
	int l = getWordcount() - 1;
	for (int i = 0; i < k; i++, l--)
	{
		 
		topKWordFreqp[i] = allWordCountArrayp[l];
	}
	
	return topKWordFreqp; 
}


//Pre-condition: {i == 0}
//Post-condition: {i < k}
int* Document::getBottomKWordFreq(int k)
{
	bottomKWordFreqp = new int[k];
	
	for (int i = 0; i < k; i++)
	{
		
		bottomKWordFreqp[i] = allWordCountArrayp[i];
	}
	
	return bottomKWordFreqp; 

}



//Pre-condition: {j == 0}
//Post-condition: {j < charactercount}
char* Document::characterOffSet(int offset)
{
	char* chararrayp = parseChar();
	int charactercount = strlen(chararrayp);
	char* offsetArrayp;
	int j = 0; 
	if (charactercount%2 == 0)
		{
			
			offsetArrayp = new char[charactercount/offset+1]; //20140504, 1 for NULL 

			for (int i = 0; i < charactercount; i = i + offset)
			{
			
				offsetArrayp[j] = chararrayp[i];
				j++;
			
			}

		}
	if (charactercount%2 == 1)
		{
			
			offsetArrayp = new char[charactercount/offset + 1 +1 ]; //20140504, for null


			for (int i = 0; i < charactercount; i = i + offset)
			{
			
				offsetArrayp[j] = chararrayp[i];
				j++;
			
			}
		}
	
	offsetArrayp[j] = '\0';
	delete chararrayp;     
	return offsetArrayp;

}

//Pre-condition: {i == 0}
//Post-condition: {i < length}
void Document::caesarCipherOffset(char offset)
{
          int length = getCharcount();
          caesarCipherTextp = new char[length];
 
          char* chararrayp = parseChar();
          for (int i = 0; i < length; i++)
          {
			caesarCipherTextp[i] = chararrayp[i] + ( offset % 256 );      

          if (caesarCipherTextp[i] > 256) 
			  caesarCipherTextp[i] -= 256;
          }

		  cout << "Encrypted succesfully" << endl;
}
 
//Pre-condition: {length != 0}
//Post-condition: {length > i}
void Document::decryptCaesar(char offset)
{
          
		int length = getCharcount();

          for (int i = 0; i < length; i++)
          {
                    caesarCipherTextp[i] = caesarCipherTextp[i] - ( offset % 256 );
				
					if (caesarCipherTextp[i] < 0 )
					caesarCipherTextp[i] += 256;
          }
          
		  cout << "Decrypted successfully" << endl;
}
 
 
//Pre-condition: {j == 0}
//Post-condition: {j <= i}
void Document::vigenereCipher(string key)
{
            int charLength = getCharcount();
 
            vigenereCipherTextp = new char[charLength];
           
            char* chararrayp = parseChar();
            int keyLength = key.length();
 
            int j = 0;
            for (int i = 0; i < charLength; i++)
            {
           
            vigenereCipherTextp[i] = chararrayp[i] +  (key[ j % keyLength]  %  256    );   // same correction here
            j++;
 
           
            }

					  cout << "Encrypted succesfully" << endl;

}

//Pre-condition: {length != 0}
//Post-condition: {length != 0}
void Document::decryptVigenere(string key)
{
          int length = getCharcount();
          int j = 0;
          int leylength = key.length();
          for (int i = 0; i < length; i++)
          {
                    vigenereCipherTextp[i] = vigenereCipherTextp[i] - ( key[ j % leylength ]  % 256 );
				
				if (vigenereCipherTextp[i] < 0 ) 
					vigenereCipherTextp[i] += 256;

					j++;
          }
		  		  cout << "Decrypted successfully" << endl;

}
 
//Pre-condition: {xyLength == 2*count}
//Post-condition: {xyLength == 2*count}
double* Document::wordTrace(string* wordsp, int count)
{
	int xyLength = count*2;
	double* xAndyValuesp = new double[xyLength];
	
	int firstLine = 0; 
	
	int firstCounter = 0; 
	for (int h = 0; h < count; h++)
	{
		string test = wordsp[h];
		double firstLine = 0; 

		for (int i = 0; i < Linecount; i++)
		{
			string* wordsPerLinep = arrayofLines[i].parseWords();
			int lineWordCount = arrayofLines[i].getWordCount();

			for (int j = 0; j < lineWordCount; j++)
			{
				string word = arrayofLines[i].trim(wordsPerLinep[j]);

				if (word == wordsp[h])
				{
					firstLine = i + 1;
					xAndyValuesp[firstCounter] = firstLine; 
					firstCounter = firstCounter + 2;
					j = lineWordCount;
					i = Linecount;
				}
			}
			cout << endl;
		}

	}

	int lastCounter = 1;

	for (int h = 0; h < count; h++)
	{
	
		string test2 = wordsp[h];
		double lastLine = 0; 

		for (int i = Linecount - 1; i >= 0; i--)
		{
			string* wordsPerLine2p = arrayofLines[i].parseWords();
			int lineWordCount2 = arrayofLines[i].getWordCount();

			for (int j = 0; j < lineWordCount2; j++)
			{
			    string word = arrayofLines[i].trim(wordsPerLine2p[j]);

				if (word == wordsp[h])
				{
					lastLine = i + 1;
					xAndyValuesp[lastCounter] = lastLine; 
					lastCounter = lastCounter + 2;
					j = lineWordCount2;
					i = -1;
				}
			}
			cout << endl;

		}
	}

	int m = 0; 
	for (int i = 0; i < count; i++)
	{
		if (xAndyValuesp[m] > 0 || xAndyValuesp[m+1] > 0)
		cout << "Word: " << wordsp[i] << " was found first on line " << xAndyValuesp[m] << " and last on line " << xAndyValuesp[m+1] << endl;	

		else
			cout << "Word: " << wordsp[i] << "not found in document" << endl;
		m = m + 2;;
	}

	return xAndyValuesp;

}

//Pre-condition: {length != 0}
//Post-condition: {length != 0}
int* Document::offsetCharFreq(char* offsetArrayp, int length)
{
	int* freqp = new int[SIZEOF_CHARSET];
	char distinct_chars [SIZEOF_CHARSET];

	for (int i = 0; i < SIZEOF_CHARSET; i++)
		freqp[i] = HIGH_VALUE;

	for (int i = 0; i < SIZEOF_CHARSET; i++)
		distinct_chars[i] = 0;


	for (int i=0; i< length; i++ )
	{
		char c = offsetArrayp[i];
		int updateAt = -1;
		for ( int j = 0; j < SIZEOF_CHARSET; j++ )
		{
			if ( distinct_chars[j] == c || distinct_chars[j] == 0 ) 
			{
				updateAt = j;
				j=SIZEOF_CHARSET;
			}
		}
		if ( updateAt == -1 )
		{
			string resp;
			cout << "Insufficient space for distinct characters, increase SIZEOF_CHARSET" << endl;
			cin >> resp;
			exit(0);
		}
		else
		{
			distinct_chars[updateAt] = c;
			if ( freqp[updateAt] == HIGH_VALUE ) freqp[updateAt] = 0;
			freqp[updateAt]++;
		}

	}
	Metrics<int> a;

	// all elements with value=HIGH_VALUE will go at the end
	a.insertionSort(freqp, SIZEOF_CHARSET);
	for ( int j = 0; j < SIZEOF_CHARSET; j++ )
		{
			if( freqp[j] == HIGH_VALUE ) { j = SIZEOF_CHARSET; break;}
			
		}

	return freqp;

}

//Pre-condition: {SIZEOF_CHARSET != 0}
//Post-condition: {SIZEOF_CHARSET != 0}
int* Document::allCharFreq()
{
	int* freqp = new int[SIZEOF_CHARSET];
	char distinct_chars [ SIZEOF_CHARSET ];

	for (int i = 0; i < SIZEOF_CHARSET; i++)
		freqp[i] = HIGH_VALUE ;

	for (int i = 0; i < SIZEOF_CHARSET; i++)
		distinct_chars[i] = 0;


	for ( int linenum = 0; linenum< Linecount; linenum++ ) {  // scan each line at a time
		string *sp = (arrayofLines + linenum )->getString();
		int len = sp->length();
		for ( int i=0; i< len; i++ )
		{
			char c = sp->at(i);
			int updateAt = -1;
			for ( int j = 0; j < SIZEOF_CHARSET; j++ )
			{
				if ( distinct_chars[j] == c || distinct_chars[j] == 0 ) 
				{
					updateAt = j;
					j=SIZEOF_CHARSET;
				}
			}
			if ( updateAt == -1 )
			{
				string resp;
				cout << "Insufficient space for distinct characters, increase SIZEOF_CHARSET" << endl;
				cin >> resp;
				exit(0);
			}
			else
			{
				distinct_chars[updateAt] = c;
				if ( freqp[updateAt] == HIGH_VALUE ) freqp[updateAt] = 0;
				freqp[updateAt]++;
			}
		}

	}
	Metrics<int> a;


	// all elements with value=HIGH_VALUE will go at the end
	a.insertionSort(freqp, SIZEOF_CHARSET);
	for ( int j = 0; j < SIZEOF_CHARSET; j++ )
		{
			if( freqp[j] == HIGH_VALUE ) { j = SIZEOF_CHARSET; }
		}

	return freqp;

}

//Pre-condition: {hashTablesize != 0}
//Post-condition: {hashTablesize != 0}
void Document::createCharSortedArray()
{

	allCharCountArrayp = new int[hashTablesize];

	for (int i = 0; i <hashTablesize; i++)


		allCharCountArrayp[i] = 0; 

	int i = 0;

	for (int j = 0; j < hashTablesize; j++)
	{
		charNode* temp = charHashTable[j];

		// temp going horizontally
		while (temp!=NULL)
		{
			allCharCountArrayp[i] = temp->getCount();
			i++;
			temp = temp->getNext();
		}
	}

	//need to sort the linked lists


	int* charcountArray2p = new int[hashTablesize];
	Metrics<int> MetricIntClass; 

	MetricIntClass.mergeSort(allCharCountArrayp, charcountArray2p, 0,hashTablesize);



}

//Pre-condition: {wc != 0}
//Post-condition: {wc != 0}
void Document::createWordSortedArray()
{
	int wc = getWordcount(); 
	allWordCountArrayp = new int[wc];

	for (int i = 0; i <wc; i++)
		allWordCountArrayp[i] = 0; 

	int i = 0;

	for (int j = 0; j < hashTablesize; j++)
	{
		hashNode* temp = hashtable[j];

		// temp going horizontally
		while (temp!=NULL)
		{
			allWordCountArrayp[i] = temp->getCount();
			i++;
			temp = temp->getNext();
		}
	}
				
	int* countArray2p = new int[wc];
	Metrics<int> MetricIntClass; 

	MetricIntClass.mergeSort(allWordCountArrayp, countArray2p, 0,wc);
}