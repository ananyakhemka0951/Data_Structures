#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/* ================================================== */
//The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning. 

void selectionSort(int arr[], int n) {
	int imin;

	// Outer iteration loop
    for (int i = 0; i < n-1; i++)
    {
        // Inner loop to find the minimum element in the array from i to n
        imin = i;
        for (int j = i+1; j < n; j++)
		{
          if (arr[j] < arr[imin])
            imin = j;
		}
        // Swap the found minimum element with the first element
        if(imin != i)
		{
		// swapping the minimum and placing it at its correct position i.e. i-th position
		int temp = arr[imin];
        arr[imin] = arr[i];
        arr[i] = temp;
		}
            
    }
}





/* ================================================== */
//The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
void insertionSort(int arr[], int n)
{
	int j;
    for (int i = 1; i < n; i++)//inner loop to iterate through the array from 1st position to last as the inner loop will start from i-1 {
		int compare=arr[i];
        for(j=i-1; j>=0 && arr[j]>compare; j--) //iteration to compare arr[i] with elements before arr[i], Thus j=i-1
		{
            arr[j + 1] = arr[j];  // moving elements of the array that are greater that wall to one position ahead of their current position
        }
        arr[j] = compare;
    }
}










/* ================================================== */
//QUICK SORT: The array is virtually split into a sorted and an unsorted part. Values f

int partition(int *a, int leftmost, int rightmost){
  //assign pivot index to thre rightmost element of the array  
  int pivot = a[rightmost];
  int ind = leftmost;
  for (int i = leftmost; i < rightmost; i++){
      if(a[i] <= pivot){
          int temp = a[i];
          a[i] = a[pIndex];
          a[ind] = temp;
          ind++;
      }
  }
  int temp = a[ind];
  a[ind] = a[rightmost];
  a[rightmost] = temp;
  return pIndex;
}

void quickSort(int *a, int leftmost, int rightmost){
    if(a && leftmost < rightmost){
        int pIndex = partition(a, leftmost, rightmost);
        quickSort(a, leftmost, pIndex-1);
        quickSort(a, pIndex+1, rightmost);
    }
}






/* ================================================== */


int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//function to print the array with a pointer
void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}




/* ================================================== */


int main(int argc, char **argv) {
	
	//Selection sort
	int n = 10;
	int arr[n];

	printf("Enter the elements of the array");
	int x=0;
	for (int i=0; i<n; i++)
		{
			scanf("%d",&x);
			arr[i]=x;
		}


	printArray(arr, n);

	selectionSort(arr, n);
	printf("Selection Sort:");
	printArray(arr, n);



	//Insertion sort
	printf("Enter the elements of the array for insertion sort");
	int a=0;
	for (int i=0; i<n; i++)
		{
			scanf("%d",&a);
			arr[i]=a;
		}


	printArray(arr, n);

	insertionSort(arr, n);
	printf("Insertion Sort:");
	printArray(arr, n);


	//Quick Sort
	int * a;
	  int n = 10;

	  srand(time(NULL));

	  a = generateArray(n);
    printArray(a,n);
    selectionSort(a, n);

    printf("Sorted array: \n");
    quickSort(a, 0, n-1);



	return 0;
}









