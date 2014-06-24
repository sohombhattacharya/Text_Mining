//Sohom Bhattacharya
//Metrics.h
//  void selectionSort(Type* a, int size);-----------------------------------------> Selection sort function based on the Type of list entered. 
//	void insertionSort(Type* a, int size);-----------------------------------------> Insertion sort function based on the Type of list entered. 
//	void mergeSort(Type* a, Type* b, int low, int high); --------------------------> Merge sort function based on the Tpe of the list entered. 
//	void merge(Type *a, Type *b, int low, int pivot, int high);--------------------> Merge function used in Merge sort function based on the list entered. 
//	
//	//need a sort for linked list 
//	hashNode* sortLinkedList(hashNode* head);--------------------------------------> Linked list sort for hashNodes. 
//	charNode* charSortLinkedList(charNode* head);----------------------------------> Linked list sort for charNodes. 
//
//	//need three separate elementary sorts to sort strings
//	void selectionSortStrings(string a[], int size);-------------------------------> Selection sort for strings. 
//	void insertionSortStrings(string a[], int size);-------------------------------> Insertion sort for strings.


#ifndef Met
#define Met
#include <string>
#include <iostream>
#include <cstdlib>
#include "hashNode.h"
#include "charNode.h"

using namespace std; 


template <class Type>
class Metrics
{

public: 
	void selectionSort(Type* a, int size);
	void insertionSort(Type* a, int size);
	void mergeSort(Type* a, Type* b, int low, int high); 
	void merge(Type *a, Type *b, int low, int pivot, int high);
	
	//need a sort for linked list 
	hashNode* sortLinkedList(hashNode* head);
	charNode* charSortLinkedList(charNode* head);

	//need three separate elementary sorts to sort strings
	void selectionSortStrings(string a[], int size);
	void insertionSortStrings(string a[], int size);

	
private: 
	int id; 

};
#endif 