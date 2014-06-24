//Sohom Bhattacharya
//Metrics.cpp
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

#include "Metrics.h"


//Pre-condition: {i == 0}
//Post-condition: {i < (size - 1)}
template <class Type>
void Metrics<Type>::selectionSort(Type* a, int size)
{
	int minIndex;
	Type temp; 

	for (int i=0; i < size-1; i++)
	{
	    minIndex = i;
		
		for (int j=i+1; j < size; j++)
		{

			if (*(a + j) < *(a + minIndex))
                   minIndex=j;
		}
		
			if (minIndex != i)
            {
                 temp = *(a + i);
                 *(a + i) = *(a + minIndex);
                 *(a + minIndex) = temp;
            }
	}
}

//Pre-condition: {size > 0}
//Post-condition: {size > i}
template <class Type>
void Metrics<Type>::insertionSort (Type* a, int size)
{
	 	int j; 
		Type temp;
		
	for (int i = 0; i < size; i++)
	{
		j = i;
		
		while (j > 0 && *(a + j) < *(a + (j-1)))
			{
			  temp = *(a + j);
			  *(a + j) = *(a + (j-1));
			  *(a + (j-1)) = temp;
			  j--;
			 }
	}

	
	
}

//Pre-condition: {pivot <= high} 
//Post-condition: {pivot <= high}
template <class Type>
void Metrics<Type>::merge(Type *a, Type *b, int low, int pivot, int high)
{
	int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=high; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}

//Pre-condition: {low < high}
//Post-condition: {low <= high}
template <class Type>
void Metrics<Type>::mergeSort(Type *a, Type *b, int low, int high)
{
    int pivot;

    if(low<high)
    {
        pivot=(low+high)/2;
        mergeSort(a,b,low,pivot);
        mergeSort(a,b,pivot+1,high);
        merge(a,b,low,pivot,high);
    }
}

//Pre-condition: {i < (size-1)}
//Post-condition:{i < j}
template <class Type>
void Metrics<Type>::selectionSortStrings(string a[], int size)
{

	int minIndex;
	string temp; 

	for (int i=0; i < size-1; i++)
	{
	    minIndex = i;
		
		for (int j=i+1; j < size; j++)
		{

			if ((*(a + j).size) < (*(a + minIndex).size))
                   minIndex=j;
		}
		
			if (minIndex != i)
            {
                 temp = *(a + i);
                 *(a + i) = *(a + minIndex);
                 *(a + minIndex) = temp;
            }
	}
	


}


//Pre-condition: {i == 0}
//Post-condition: {i < size}
template <class Type> 
void Metrics<Type>::insertionSortStrings(string a[], int size)
{

		int j; 
		string temp;
		
	for (int i = 0; i < size; i++)
	{
		j = i;
		
		while (j > 0 && a[j].size() < a[j-1].size())
		{
			  temp = a[j];
			  a[j] = a[j-1];
			 a[j-1] = temp;
			  j--;
			  }
		}
}
	


//Pre-condition: {head != NULL}
//Post-condition: {head != NULL}
template <class Type> 
hashNode* Metrics<Type>::sortLinkedList(hashNode* head)
{
	if (head == NULL || head->getNext() == NULL)
		return head; 

	hashNode *savedHead = head;
	while ( head != NULL ) 
	{
		hashNode *next = head->getNext();
		while ( next!= NULL ) 
		{
			if ( next->getCount() >= head->getCount() ) 
			{
				// swap the counts
				int count = next->getCount();
				next->setCount( head->getCount() );
				head->setCount( count );

				// swap the word
				string s = next->getWord();
				next->setWord( head->getWord() );
				head->setWord(s); 
			}
			next  = next->getNext();
		}
		head= head->getNext();
	}

	return savedHead;
}


//Pre-condition: {head != NULL}
//Post-condition: {head != NULL}
template <class Type> 
charNode* Metrics<Type>::charSortLinkedList(charNode* head)
{
	if (head == NULL || head->getNext() == NULL)
		return head; 

	charNode* newHead = head; 
	charNode* afterHead = head->getNext();

	while(afterHead != NULL)
	{
	charNode* insidePointer = newHead; 
	charNode* next = afterHead->getNext();

		if (afterHead->getCount() <= newHead->getCount())
		{
		charNode* oldHead = newHead; 
		newHead = afterHead; 
		newHead->setNext(oldHead);
		}
		
		else
		{
			while (insidePointer->getNext() != NULL)
			{
			
				if (afterHead->getCount() > insidePointer->getCount() &&  afterHead->getCount() <= insidePointer->getNext()->getCount())
				{
					charNode* nextOld = insidePointer->getNext();
					insidePointer->setNext(afterHead);
					afterHead->setNext(nextOld);
				}
				
				insidePointer = insidePointer->getNext();
			}
		
			if (insidePointer->getNext() == NULL && afterHead->getCount() > insidePointer->getCount())
			{
			insidePointer->setNext(afterHead);
			afterHead->setNext(NULL);
			}
		
		
		}


		afterHead = next; 
	}

	return newHead; 
}

