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
  printLinkedList(list); // printing the sorted linked list
  freeLinkedList(list);
  return 0;
}
