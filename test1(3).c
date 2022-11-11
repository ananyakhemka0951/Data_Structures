#include <stdio.h>
#include <stdlib.h>

int * blah(int val) {
	int x;
	int * pointer = &x;
	x = val*val;
	return pointer;
}

int alloc() {
    int * a;
    int i, n, val;

    n = 3;
    a = malloc(n * sizeof(int));

    // enter data
    i = 0;
    scanf("%d", &val);
    while(val>0){
        a[i] = val;
        i = i+1;
        if(i>=n) {
            n = n*2;
            a = realloc(a, n * sizeof(int));
        }
        scanf("%d", &val);
    }
    n = i;
    a = realloc(a, n * sizeof(int));

    // print data
    for(i=0; i<n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n\nDone!\n");
    
    return 0;
}

int main(int argc, char **argv) {
	int * b = blah(5);
	printf("%d.\n", *b);
	
	int n=alloc();
	return 0;
}
