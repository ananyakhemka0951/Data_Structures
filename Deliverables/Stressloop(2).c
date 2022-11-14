

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){

    float i;
    float increment = 0.000000001; //Change around this
    float n = 0.00000001; //And this (this is 10 times increment)
    int count = 1;

    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count++;
    }

    return 0;
}
