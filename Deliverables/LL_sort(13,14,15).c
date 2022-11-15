#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int val;
	struct node * next;	
};

typedef struct node * NodeAddress; // creating a new data type called NodeAddress which is the address of the node;




/* ================================================== */
//SELECTION SORT: The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from the unsorted part and putting it at the beginning. 
//Implementing selection sort by swapping the data in the given address
void selectionsort(NodeAddress head)
{
  NodeAddress temp=head;
  NodeAddress min;
	while(temp!=NULL) // Outer iteration loop
	{
		min=temp;
		NodeAddress j=min->next; // j is being used to traverse through the linklist from temp to NULL. This is the inner loop to find out the minimum element from temp to Null.
		while(j!=NULL)
		{
			if(j->val < min->val)
			{
				min=j; //if th value at j is less than that of min, it keeps of storing it in min until we find the minimum element
			}
			j=j->next; // It increments the address of j to traverse through the linked list
		}
		//To place the mimum elemeent in its correct position (temp) by swapping
		int t=temp->val;
		temp->val=min->val;
		min->val=t;
		temp=temp->next; // It increments the address of temp to traverse through the linked list
	}
}



/* ================================================== */
//INSERTION SORT: The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

NodeAddress insertionSort(NodeAddress head, NodeAddress sorted)
{
	NodeAddress current = head;
    // NodeAddress current  is being used to traverse through the linked list and insert every element in NodeAddress sorted
    while (current != NULL) // till current reaches NULL
	{
        NodeAddress next = current->next; // Store next for next iteration
        sortedInsert(current, sorted);// sortedInsert takes the pointer current and inserts the element in sorted
        // Update current
        current = next;
    }
    // Update head to point to the start of the sorted linked list and return it
    head = sorted;
	return head;
}


void sortedInsert(NodeAddress newnode, NodeAddress sorted)
{
    // Special case for the head end along with checking if sorted->data >= newnode->data
    if (sorted == NULL || sorted->data >= newnode->data) 
	{
        newnode->next = sorted;
        sorted = newnode;
    }
    else 
	{
        NodeAddress c = sorted;
        // Locate the node before the point of insertion
        while (c->next != NULL && c->next->data < newnode->data) 
		{
            c = c->next;
        }
        newnode->next = c->next;
        c->next = newnode;
    }
}


/* ================================================== */
//Creating a linked list

NodeAddress linkedList(int n){
	int i;
	NodeAddress head = NULL;
	NodeAddress temp = NULL;
	int x=0;

	// special case for head
	if(n>0) {
		head = malloc(sizeof(struct node) );
		printf("Enter the elements \n");
		scanf("%d",&x);
		head->val  = x;
		head->next = NULL;
		temp = head;
	}


	for(i=1; i<n; i++) {
		temp->next = malloc( sizeof(struct node) );// allocating space for the element of the linked list along with the address of the next node
		temp = temp->next; // sotring the address if next node
		scanf("%d",&x);
		temp->val = x; // storing the value of the element 
		temp->next = NULL;
	}

	return head;
}





/* ================================================== */
//Printing the linked list
void printLinkedList(NodeAddress head) {
	NodeAddress c;
	printf("Linked List = ");
	for(c=head; c!=NULL; c=c->next) {
		printf( c==head?"%d":", %d", c->val);
	}
	printf(".\n");
}

//To free the space used by the linked list
void freeLinkedList(NodeAddress head) {
	NodeAddress prev;
	while(head) {
		prev = head;
		head = head->next;
		free(prev);
	}
}





/* ================================================== */
int main(int argc, char **argv) {
	printf("Enter the size\n");
    int n;
    scanf("%d",&n);
    
	if(n<=0){
        printf("Size should be greater than 0");
        return 0;
    }

	

	NodeAddress list;// to store the head of the initial linked list
	list=linkedList(n);// creating a linked list and storing the head in the list
   printLinkedList(list); // printing the linked list that was entered 


  selectionsort(list); // Selection sort
  	printf("Selection Sort ");
  	printLinkedList(list); // printing the sorted linked list



	
	
	//Insertion sort
	NodeAddress sorted=NULL;


	//Creating a linked list for Insertion sort
	printf("Enter the size\n");
    int a;
    scanf("%d",&a);
    
	if(a<=0)
	{
        printf("Size should be greater than 0");
        return 0;
    }

	NodeAddress list1;// to store the head of the initial linked list
	list1=linkedList(a);// creating a linked list and storing the head in the list
    printLinkedList(list1); // printing the linked list that was entered 


	NodeAddress h= insertionSort(list1, sorted);
	printf("Insertion Sort:");
	printLinkedList(h); // printing the sorted linked list





  freeLinkedList(list);
  freeLinkedList(list1);
  freeLinkedList(list2);
  return 0;
}
