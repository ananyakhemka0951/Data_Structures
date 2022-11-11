#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/* ================================================== */
//The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning. 

void selectionSort(int arr[], int n) {
	int imin;

	// Outer iteration loop
    for (int i = 0; i < n-1; i++) // As j will start from i+1, thus i < n-1. 
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
		int temp = arr[imin];
        arr[imin] = arr[i];
        arr[i] = temp;
		}
            
    }
}










/* ================================================== */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}





/* ================================================== */


int main(int argc, char **argv) {
	
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


	return 0;
}
