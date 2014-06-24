//Sohom Bhattacharya
//main.cpp

#include "document.h"
#include "line.h"
#include "hashNode.h"
#include "Metrics.h"
#include "node.h"
#include "plot.h"
#include "stack.h"
#include "charNode.h"
#include "const.h"
#include <time.h>


using namespace std; 

int main(int argc, char **argv)
{
	cout << "Text Mining Program" << endl;
	cout << " " << endl;

	
	
	
	
	string program = "yes";

	while (program == "yes")
	{
	
	string textfile;
	string fileLocation;
	string outputfileLocation; 
	int decision = 0;
	int decision2 = 0; 
	int decision3 = 0;
	int decision4 = 0; 
	int decision5 = 0; 
	int decision6 = 0; 
	clock_t d1, d2;
	Document* arrayDocuments = new Document[MAX_NO_DOCS];
	

	string loadDecision = "yes";
	int i = 0;

	//1. Load Document
	while(loadDecision == "yes")
	{ 

		cout << "Please enter the name of a document" << endl;
		cin >> textfile;

		arrayDocuments[i].setStringname(textfile);

		cout << "Please enter the location of the file" << endl;
		cin >> fileLocation;

		cout << "Loading " << fileLocation << endl;

		arrayDocuments[i].loadDocument(fileLocation);

		cout << "Loading done" << endl;

		cout << "Would you like to load another document? Enter yes or no" << endl;
		cin >> loadDecision;

		i++;
	}

	string analyzeDoc = "yes";

	while (analyzeDoc == "yes")
	{
	cout << " " << endl;
	cout << "Output the file\t[1]\n\nCharacter count\t[2]\n\nWord count\t[3]\n\nSentence count\t[4]\n\nCharacter histogram\t[5]\n\nCharacter histogram with offset\t[6]\n\nTop K words\t[7]\n\nBottom K words\t[8]\n\nWord trace\t[9]\n\nCompare two documents\t[10]\n\nEncrypt\t[11]\n\nDecrypt\t[12]" << endl;
	cin >> decision; 




	string documentName; 
	int place = -1; 
	int secondPlace = -1;
	int offset = 0;
	int k = 0;
	char off;
	string vigenereWord; 
	int wordTraceCount = 0;
	string* words; 




	switch (decision)
	{



	case 1:				cout << "Enter the document name" << endl;
					cin >> documentName; 


					for (int i = 0; i < MAX_NO_DOCS; i++)
					{
						if (arrayDocuments[i].getString() == documentName)
						place = i; 
					}

					if (place != -1)
					{
						cout << "Enter the output location" << endl;
						cin >> outputfileLocation; 

						arrayDocuments[place].outputDocument(outputfileLocation);
						cout << "Output succesful" << endl;
					
					}
		



		break;

	case 2:				cout << "Enter the document name" << endl;
		cin >> documentName; 

		for (int i = 0; i < MAX_NO_DOCS; i++)
		{
			if (arrayDocuments[i].getString() == documentName)
				place = i; 
		}

		if (place != -1){
			int c = arrayDocuments[place].getCharcount();
			cout << "Character count is " << arrayDocuments[place].getCharcount() << endl;
		}

		break;

	case 3:				cout << "Enter the document name" << endl;
		cin >> documentName; 

		for (int i = 0; i < MAX_NO_DOCS; i++)
		{
			if (arrayDocuments[i].getString() == documentName)
				place = i; 
		}

		if (place != -1)
			cout << "Word count is " << arrayDocuments[place].getWordcount() <<  endl;

		break;

	case 4:				cout << "Enter the document name" << endl;
		cin >> documentName; 

		for (int i = 0; i < MAX_NO_DOCS; i++)
		{
			if (arrayDocuments[i].getString() == documentName)
				place = i; 
		}

		if (place != -1){
			int c = arrayDocuments[place].getLinecount();
			cout << "Sentence count is " << c<<  endl;
		}

		break; 

	case 5:				cout << "Enter the document name" << endl;
		cin >> documentName; 

		for (int i = 0; i < MAX_NO_DOCS; i++)
		{
			if (arrayDocuments[i].getString() == documentName)
				place = i; 
		}

		if (place != -1)
		{

			int* frequencies = arrayDocuments[place].allCharFreq();
			int length = 0;
			for (int i = 0; i < SIZEOF_CHARSET; i++)
			{
				if (frequencies[i] == HIGH_VALUE)  // 20140504
					i = SIZEOF_CHARSET; 

				else
					length++;

			}

			Plot a;
			a.histogram(frequencies, length);


		}
		break; // 20140503 FIX
	case 6:	//character histogram with offset 

		cout << "Enter the document name" << endl;
		cin >> documentName; 



		for (int i = 0; i < MAX_NO_DOCS; i++)
		{
			if (arrayDocuments[i].getString() == documentName)
				place = i; 
		}

		if (place != -1)
		{
			cout << "Enter a number for offset" << endl;
			cin >> offset; 
			int length = 0;
			//call a function that takes this offset as a parameter and creates a new character array based on offset 
			char* offsetArray = arrayDocuments[place].characterOffSet(offset);
			length = strlen( offsetArray) ; // 20140504
			int* freq = arrayDocuments[place].offsetCharFreq(offsetArray, length);
			int newLength = 0; 

			for (int i = 0; i < length; i++)
			{
				if (freq[i] == HIGH_VALUE )
					i = length; 

				else
					newLength++;


			}
			Plot a;
			
			a.histogram(freq, newLength);
		}
		break;

	case 7: //top k words
		cout << "Hash method[1] or sort method[2]?" << endl;
		cin >> decision3;


		switch (decision3)
		{

		case 1:						
			cout << "Enter the document name" << endl;
			cin >> documentName; 

			cout << "Enter a value for K" << endl;
			cin >> k;

			for (int i = 0; i < MAX_NO_DOCS; i++)
			{
				if (arrayDocuments[i].getString() == documentName)
					place = i; 
			}

			if (place != -1)
			{

				arrayDocuments[place].createWordHashtable();
				arrayDocuments[place].createWordSortedArray();
				int* freq = arrayDocuments[place].getTopKWordFreq(k);

				Plot a;
				cout << "Top " << k << endl;
				for( int i =0; i< k; i++ )
				cout << "(" << i << ")=" << freq[i] << endl; 
				d1 = clock();
				a.histogram(freq,k);
				d2 = clock();
				cout << "Time:  " << ((double)(d2-d1))/(CLOCKS_PER_SEC)<<endl;


			}

			break;

		case 2:						cout << "Enter the document name" << endl;
			cin >> documentName; 

			cout << "Enter a value for K" << endl;
			cin >> k;

			for (int i = 0; i < MAX_NO_DOCS; i++)
			{
				if (arrayDocuments[i].getString() == documentName)
					place = i; 
			}

			int newLength = 0;
			if (place != -1)
			{
				//add functions


				arrayDocuments[place].allWordCountSortMethod();
				int* freq = arrayDocuments[place].getTopKWordsSortMethod(k);

				Plot a;
				d1 = clock();
				a.histogram(freq, k);	
				d2 = clock();

				cout << "Time:  " << ((double)(d2-d1))/(CLOCKS_PER_SEC)<<endl;

			}



			break;



		}
		break;
	case 8: // bottom k words

		cout << "Hash method[1] or sort method[2]?" << endl;
		cin >> decision4;


		switch (decision4)
		{

			case 1:	

			cout << "Enter the document name" << endl;
			cin >> documentName; 

			cout << "Enter a value for K" << endl;
			cin >> k;

			for (int i = 0; i < MAX_NO_DOCS; i++)
			{
				if (arrayDocuments[i].getString() == documentName)
					place = i; 
			}

			if (place != -1)
			{

				arrayDocuments[place].createWordHashtable();
				arrayDocuments[place].sortWordHashTable();
				arrayDocuments[place].createWordSortedArray();
				int* freq = arrayDocuments[place].getBottomKWordFreq(k);

				Plot a;
				a.histogram(freq,k);


			}

			break;

		case 2:						cout << "Enter the document name" << endl;
			cin >> documentName; 

			cout << "Enter a value for K" << endl;
			cin >> k;

			for (int i = 0; i < MAX_NO_DOCS; i++)
			{
				if (arrayDocuments[i].getString() == documentName)
					place = i; 
			}

			if (place != -1)
			{

				arrayDocuments[place].allWordCountSortMethod();
				int* freq = arrayDocuments[place].getBottomKWordsSortMethod(k);

				Plot a;
				a.histogram(freq, k);


			}



			break;



		}
		break;


	case 9: // Word trace					
		cout << "Enter document name" << endl;
		cin >> documentName; 

		for (int i = 0; i < MAX_NO_DOCS; i++)
		{
			if (arrayDocuments[i].getString() == documentName)
				place = i; 
		}

		if (place != -1)
		{
			cout << "Enter the number of words you would like to trace" << endl;
			cin >> wordTraceCount;

			words = new string[wordTraceCount];

			for (int i = 0; i < wordTraceCount; i++)
			{
				cout << "Please enter word " << (i+1) << endl;
				cin >> words[i];
			}

			//function that takes in wordTraceCount and string* array and returns 
			double* coordinates = arrayDocuments[place].wordTrace(words, wordTraceCount);
			double* x = new double[wordTraceCount];
			double* y = new double[wordTraceCount];
			int coorLength = wordTraceCount*2; 

			int h = 0; 
			for (int i = 0; i < coorLength; i = i + 2)
			{
				x[h] = coordinates[i];
				h++;
			}
			h = 0; 
			for (int j = 1; j < coorLength; j = j + 2)
			{
				y[h] = coordinates[j];
				h++;
			}

			Plot a;
			a.plot2D(x,y,wordTraceCount);

		}


		break;
	case 10: // compare two documents			
		cout << "Enter first document name" << endl;
		cin >> documentName; 

		for (int i = 0; i < MAX_NO_DOCS; i++)
		{
			if (arrayDocuments[i].getString() == documentName)
				place = i; 
		}

		if (place != -1)
		{
			cout << "Enter second document name" << endl; ///20140506
			cin >> documentName;

			for (int i = 0; i < MAX_NO_DOCS; i++)
			{
				if (arrayDocuments[i].getString() == documentName)
					secondPlace = i; 
			}

			if (secondPlace != -1)
			{

				cout << "Words different: " << arrayDocuments[place].reverseCompare(arrayDocuments[secondPlace]) << endl;


			}


		}

		break;

	case 11: //encrypt					
		cout << "Encrypt using Caesar cipher[1] or Vigenere cipher[2]?" << endl;
		cin >> decision5;  //20140506

		switch (decision5)
		{


		case 1:	//caesar cipher			
			cout << "Enter the document name" << endl;
			cin >> documentName; 

			cout << "Enter a character for offset" << endl;
			cin >> off;

			for (int i = 0; i < MAX_NO_DOCS; i++)
			{
				if (arrayDocuments[i].getString() == documentName)
					place = i; 
			}

			if (place != -1)
			{

				arrayDocuments[place].caesarCipherOffset(off);
			}

			break;
		case 2: //vigenere cipher
			cout << "Enter the document name" << endl;
			cin >> documentName; 

			cout << "Enter the word for key" << endl;
			cin >> vigenereWord;

			for (int i = 0; i < MAX_NO_DOCS; i++)
			{
				if (arrayDocuments[i].getString() == documentName)
					place = i; 
			}

			if (place != -1)
			{
				arrayDocuments[place].vigenereCipher(vigenereWord);

			}

			break;

			default: cout << "Incorrect value entered" << endl;

		}



		break;

	case 12: //decrypt

					cout << "Decrypt using Caesar cipher[1] or Vigenere cipher[2]?" << endl;
		cin >> decision6;  //20140506

		switch (decision6)
		{


		case 1:	//caesar cipher			
			cout << "Enter the document name" << endl;
			cin >> documentName; 

			cout << "Enter a character for offset" << endl;
			cin >> off;

			for (int i = 0; i < MAX_NO_DOCS; i++)
			{
				if (arrayDocuments[i].getString() == documentName)
					place = i; 
			}

			if (place != -1)
			{

				arrayDocuments[place].decryptCaesar(off);
			}

			break;
		case 2: //vigenere cipher
			cout << "Enter the document name" << endl;
			cin >> documentName; 

			cout << "Enter a word for key" << endl;
			cin >> vigenereWord;

			for (int i = 0; i < MAX_NO_DOCS; i++)
			{
				if (arrayDocuments[i].getString() == documentName)
					place = i; 
			}

			if (place != -1)
			{
				arrayDocuments[place].decryptVigenere(vigenereWord);

			}

			break;

		default: cout << "Incorrect value entered" << endl;
		}

		break;

	default:		cout << "Incorrect value entered" << endl;
	}

		cout << " " << endl;
		cout << "Would you like to work with these documents again? Enter yes or no" << endl; 
		cin >> analyzeDoc;
		

	}
	
		cout << "Would you like to run the program again? Enter yes or no" << endl;
		cin >> program;

	}




	system("pause");
}