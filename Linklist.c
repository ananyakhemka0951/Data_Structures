#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};
typedef struct node * NodeAddress; // creating a new data type called NodeAddress which is the address of the node

/* ================================================== */
void bubbleSort(int * a, int n) {
	int done, i, t, swap;

	for(done=0; done<n; done++) {

		swap = 0;
		for(i=0; i<n-1-done; i++) {

			if( a[i] > a[i+1] ) {
				// swap these elements since they are in the wrong order
				t      = a[i];
				a[i]   = a[i+1];
				a[i+1] = t;
				swap   = 1;
			}

		} // end of the i loop
		if(swap==0)
			break;

	} // end of the done loop
}

NodeAddress bubbleSortLinkedList(NodeAddress head) {
	NodeAddress c, lastDone;
	int t;

	for(lastDone = NULL; lastDone!=head; lastDone=c) {

		for(c=head; c->next!=lastDone; c=c->next) {

			if( c->val > c->next->val ) {
				t = c->val;
				c->val = c->next->val;
				c->next->val = t;
			}

		} // end of c loop; the element has been bubbled up to position c

	}
	return head;
}

/* ================================================== */
int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}

NodeAddress linkedListFromArray(int * a, int n) {
	int i;
	NodeAddress head = NULL;
	NodeAddress temp = NULL;

	// special case for head
	if(n>0) {
		head = malloc( sizeof(struct node) );
		head->val  = a[0];
		head->next = NULL;
		temp = head;
	}


	for(i=1; i<n; i++) {
		temp->next = malloc( sizeof(struct node) );
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}

	return head;
}

void freeLinkedList(NodeAddress head) {
	NodeAddress prev;
	while(head) {
		prev = head;
		head = head->next;
		free(prev);
	}
}

/* ================================================== */
void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf(" %d ", a[i]);
	}
}

void printLinkedList(NodeAddress head) {
	NodeAddress c;
	printf("Linked List = ");
	for(c=head; c!=NULL; c=c->next) {
		printf( c==head?"%d":", %d", c->val);
	}
	printf(".\n");
}

/* ================================================== */
int main(int argc, char **argv) {
	int * a;
	int n = 10;
	NodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	list = linkedListFromArray(a,n);

	printArray(a,n);
	bubbleSort(a,n);
	printArray(a,n);

	printLinkedList(list);
	bubbleSortLinkedList(list);
	printLinkedList(list);

	free(a);
	freeLinkedList(list);

	return 0;
}