//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link-> https://practice.geeksforgeeks.org/problems/swap-two-numbers3844/1



//Method 1->
//Using temporary variables;
#include <stdio.h>

void main()
{
int x=10, y=20, temp;

printf("Before Swapping\n x = %d\n y = %d\n", x, y);

temp = x;
x = y;
y = temp;

printf("After Swapping\n x = %d\n y = %d\n", x, y);
}





//Method 2->
//Swapping can be done also without using a third variable.
//x=x+y;//This will modify x=30 & y=20
//y=x-y;//This will modify y value i.e y=10 & x=30
//x=x-y;//This will modify x value i.e x=20 & y=10


#include <stdio.h>

void main()
{
int x=10, y=20;

printf("Before Swapping\n x = %d\n y = %d\n", x, y);

x=x+y;
y=x-y;
x=x-y;

printf("After Swapping\n x = %d\n y = %d\n", x, y);
}


//further we can use this logic to apply on multiplication and division to get the swapping


//Method 3-> 

//Using XOR operator we can also swap two numbers.



#include <stdio.h>
void main()
{
int x=10, y=20;

printf("Before Swapping\n x = %d\n y = %d\n", x, y);

x=x^y;
y=x^y;
x=x^y;

printf("After Swapping\n x = %d\n y = %d\n", x, y);
}




//Method 4-> Using pointers

#include <stdio.h>

void main()
{
int x=10, y=20,*ptr1,*ptr2,temp;;

printf("Before Swapping\n x = %d\n y = %d\n", x, y);
ptr1 = &x;
ptr2 = &y;

temp = *ptr2;
*ptr2 = *ptr1;
*ptr1 = temp;

printf("After Swapping\n x = %d\n y = %d\n", x, y);
}


//Method 5->
//Using fuction 
#include <stdio.h>

void swap(int*, int*); //function declaration

void main()
{
int x=10, y=20;

printf("Before Swapping\nx = %d y = %d\n", x, y);

swap(&x, &y); //function call

printf("After Swapping\nx = %d y = %d\n", x, y);
}
//function definition
void swap(int *ptr1, int *ptr2)
{
int temp;
temp = *ptr2;
*ptr2 = *ptr1;
*ptr1 = temp;
}



//Thanks!!!!!!!!!!!!!!!!!!!!!
