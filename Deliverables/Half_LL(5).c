#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int val;
	struct node * next;	
};
typedef struct node * NodeAddress; // creating a new data type called NodeAddress which is the address of the node;





/* ================================================== */
//To find out the length and the miidle length of the linkedlist
void half_ll(NodeAddress head)
{
  NodeAddress hare;
  NodeAddress tortoise;  
  // We are creating two NodeAddress hare and tortoise. In this hare will increment twice as fast as tortoise thus, by the time hare reaches null, the tortoise will be in the middle
  hare = head;
  tortoise = head;
  while(hare!=NULL)
  {
  printf("%d\n",tortoise->val); // printing the element at NodeAddress tortoise as the pointer can only increment till middle of the linked list
  // incrementing the hare twice as fast as tortoise
   hare = hare -> next;
   hare = hare -> next;
   tortoise = tortoise->next;
}
}


/* ================================================== */
//Creating a linked list

NodeAddress linkedList(int n) {
	int i;
	NodeAddress head = NULL;
	NodeAddress temp = NULL;
	int x=0;

	// special case for head
	if(n>0) {
		head = malloc( sizeof(struct node) );
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


  half_ll(list); // printing the half linked list without knowing the length of the linked list

  freeLinkedList(list);
  return 0;
}
