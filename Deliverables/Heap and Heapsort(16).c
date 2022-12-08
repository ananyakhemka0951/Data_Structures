#include<stdio.h>
#include<stdlib.h>


// Function to swap two elements 
void swap(int* x, int* y)
{
 
    int t = *x;
 
    *x = *y;
 
    *y = t;
}
 


/* ================================================== */ 
//Function to heapify all the elements in the subtree

void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than the value stored in largest
    if (left < N && arr[left] > arr[largest])
    {
        largest = left;
    }
 
 
    // If right child is larger than the value stored in largest
    if (right < N && arr[right] > arr[largest])
    {
        largest = right;
    }
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
//Function to to call anpther function to heapify all elements and then heapsort it
void heapSort(int arr[], int N)
{
 
    // Build max heap
 //last index of the non-leaf node whose index is given by n/2 – 1. 
 //i starts from the last index of the non-leaf node as the node is compared with its children and then we traverse upwards.
    for (int i = N / 2 - 1; i >= 0; i--)//Function to find the largest element and switching it till it becomes the root
    {
 
        heapify(arr, N, i);
    }
 
    // Function to sort the elements and then heapify them
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}
 




/* ================================================== */ 
//Function to print the array
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}





/* ================================================== */ 
int main(int argc, char **argv)
{
    printf("Enter the size of array");
    int n;
    scanf("%d", &n);
    int * arr = malloc(n*sizeof(int)) ;

 
    //To input the elemets of the array
         printf("Enter the elements");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    } 

    
    arr = heapsort(arr, n);    

     printf("sorted array: ");
     printArray(arr,n);

    return 0; ;
}
