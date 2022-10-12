#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

/* ================================================== */
int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}

/* ================================================== */
void printArray(int *a, int n) {
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

/* ================================================== */
int main(int argc, char **argv) {
	int * a;
	int n = 10;

	srand(time(NULL));

	a = generateArray(n);
	printArray(a,n);
	bubbleSort(a,n);
	printArray(a,n);

	free(a);
	return 0;
} 