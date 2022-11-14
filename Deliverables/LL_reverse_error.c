#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};
typedef struct node * NodeAddress; // creating a new data type called NodeAddress which is the address of the node


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
		temp->next = malloc( sizeof(struct node) );
		temp = temp->next;
		scanf("%d",&x);
		temp->val = x;
		temp->next = NULL;
	}

	return head;
}

/* ================================================== */
//Reversing a linked list
NodeAddress reverse(NodeAddress head)
{
	NodeAddress prev= NULL;
	NodeAddress current=head;
	NodeAddress next=NULL;

	while(current!=NULL){
		next=current->next;

		//As in reversing a linked list, we have to reverse the pointers, reversing current node's pointer
		current->next=prev;

		//moving pointers ahead
		prev=current;
		current=next;
	}
	head=prev; // can return prev also
	return head;

}

//Chunk-reversing a linked list
NodeAddress Chunkreverse(NodeAddress head) // Error in the function: Only prints the first element of the linked list. Error corrected in the file named 'LL_reverse.c'
{
	printf("Enter the integer to represent the chunk size \n");
	int k;
	scanf("%d",&k);
	int c=0;

	NodeAddress prev= NULL;
	NodeAddress current=head;
	NodeAddress next=NULL;
    NodeAddress start=head;

	while(current!=NULL && c<k) //for(int i=0; i<k && current!=NULL; i++)
    {
		next=current->next;

		//reversing current node's pointer
		current->next=prev;

		//moving pointers ahead
		prev=current;
		current=next;

        c++;// for iteration till k 
		
	}
    //The pointers till kth element has been reversed
    // After the loop, the 'current' and 'next' points to the (k+1)th element in the linked list. 
    //'start' points to the the first element of the inital linked list(head).
    //Till the kth element, the pointers are reversed but from (k+1), the pointer is towards the (k+2) and so on till NULL. Thus to reverse the chunk k, the 'start' should now point towards (k+1) element and so on till NULL.
	start->next=current; 
	return prev; //pointer to the kth element
}

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

	//int x=0;

	NodeAddress list;// to store the head of the initial linked list
	list=linkedList(n);
    printLinkedList(list);

	NodeAddress revhead;
	revhead=reverse(list); 
    printf("Reverse ");
	printLinkedList(revhead);

    list=reverse(revhead);
	NodeAddress Chunk_rev_head;
	Chunk_rev_head=Chunkreverse(list);
    printf("Chunk Reverse ");
	printLinkedList(Chunk_rev_head);



    freeLinkedList(list);

	return 0;
}
