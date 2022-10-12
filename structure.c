#include<stdio.h>
#include<stdlib.h>
struct Student{
int rollNumber;
int grade;
};

int main() {
struct Student Student1;
Student1.rollNumber = 1095;
Student1.grade = 98;

struct Student* ptr = malloc(sizeof(struct Student));
ptr->rollNumber = 1785;
ptr->grade = 67;

printf("Using direct reference to the structure: %d\n", Student1.grade);

printf("Using a pointer to the structure: %d\n", ptr->grade);
printf("Using a pointer to the structure: %d\n", (*ptr).grade);
//The two printf statements just above will print the same thing
return 0;
}