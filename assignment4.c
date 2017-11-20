//Assignment 4 Data Structures and Algorithms by Sarthak Sharma (030202551).  The program reads 18 numbers
//from a text file called numbers.txt.  The numbers are then placed in an array
//from there the numbers are sorted via quick sort algorithm method and an
//insertion sort algorithm in decreasing order.  

#include<stdio.h>
#include<stdlib.h>


int insertionCount = 0; //comparison for insertionSort
int quickSortCount = 0; //comparison for quickSort
//Int Max gives the size of the A array
int MAX = 18; //Global variable gets the size of the array
void insertionSort(int arrayX[]); // Prototype function insertionsort
void quickSort(int arrayX[], int lowestNumber, int highestNumber); //Prototype function for quickSort
int partition (int arrayX[], int lowestNumber, int highestNumber);//Prototype function needed to perform quickSort 
void swap(int* a, int* b); //Prototype funciton needed to perform quickSort
void printArray(int arrayX[]); //Prototype function that prints the QuickSorted Array
void loadNumbers();

int main () { //Start of main method
	
	int A2[18];
	loadNumbers(A2);

	quickSort(A2, 0, MAX-1);
	printf("\n\nThe elements in the sorted order with quick sort in descending order are: \n");
	printArray(A2);
	printf("\n\nValue of comparison is %d ", quickSortCount);
	printf("\n\nThe elements in the sorted order with insertion sort in descending order are: \n");
	insertionSort(A2);
	printArray(A2);
	printf("\n\nValue of the comparison is %d ", insertionCount);
		


}//End of main method

void loadNumbers(int A2[]) 
{
int a; //variable used to complete file reading process 
	printf("Enter the numbers you want to sort: ");
	FILE *myFile;
	myFile = fopen("numbers.txt", "r+");
	if (myFile==NULL)
	{
		printf("File not found \n ");
	}
	for (a = 0; a < MAX; a++) 
	{
		fscanf(myFile,"%d",&A2[a]);
	}
	for (a = 0; a < MAX; a++) //For loop to print the numbers from the File
	{
		printf("%d  ",A2[a]);
	}

}//end of loadNumbers method

//insertionSort method - takes the A2 array as parameter
//reverses the array, deletes the duplicated elements and counts number of comparisons
void insertionSort(int arrayX[])
{
	int i,j,key,temp;

	for(j = 1; j < MAX; j++) //For loop traverses the entire A2 array
	{	
		//key = arrayX[j];
		i = j;
		insertionCount++; //Start counting for comparisons

		while((i > 0) && (arrayX[i-1] < arrayX[i]))	
		{
			if(arrayX[i-1]<arrayX[i]);	
			insertionCount++;	
		}
		temp=arrayX[i-1];
		arrayX[i-1]=arrayX[i];
		arrayX[i]=temp;

		i--;
		
	}

}//end of insertionSort method


//Swap method swaps two variables.  Required to perform quick sort.
void swap(int* swap1, int* swap2)
{
    int x = *swap1;
    *swap1 = *swap2;
    *swap2 = x;
}

//Partition method needed to perform quick sort
int partition (int arrayX[], int lowestNumber, int highestNumber)
{
    int pivot = arrayX[highestNumber];    // Start with the highest number in the array set it as pivot
    int i = (lowestNumber - 1);  // Let i equal to the lowest number in the array
 
    for (int j = lowestNumber; j <= highestNumber - 1; j++)
    {
		quickSortCount++;
        // If current element is smaller than or
        // equal to pivot
        if (arrayX[j] >= pivot) //Sort array in descending order
        {
            i++;    // increment index of smaller element
			
            swap(&arrayX[i], &arrayX[j]);
			quickSortCount++;
        }
    }
    swap(&arrayX[i + 1], & arrayX[highestNumber]);
    return (i + 1);
}
 

//Quick Sort method.  Takes in array as parameter, lowestNumber is the starting index
//highestNumber is the ending index
void quickSort(int arrayX[], int lowestNumber, int highestNumber)
{
    if (lowestNumber < highestNumber)
    {
		//let variable pi equal the partition method, partitioned index
        int pi = partition(arrayX, lowestNumber, highestNumber);
        // Separately sort elements before
        // partition and after partition
        quickSort(arrayX, lowestNumber, pi - 1);
        quickSort(arrayX, pi + 1, highestNumber);
		
    }
}

//printArray Method prints the Array
void printArray(int arrayX[])
{
    for (int i=0; i < MAX; i++) // Uses the global variable MAX to get the size of the A2 array
    printf("%d ", arrayX[i]);
   
}
 
