//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link-> https://www.codingninjas.com/studio/problems/next-greater-element_670312?leftPanelTab=0

//Method 1-> 
//The idea is to use two loops , The outer loop picks all the elements one by one. The inner loop looks for the first greater element for the element picked by the outer loop. 
//If a greater element is found then that element is printed as next, otherwise, -1 is printed.
//Time Complexity-> O(N*N)
//Space Complexity-> O(1)
// Simple C++ program to print
// next greater elements in a
// given array
#include <iostream>
using namespace std;

/* prints element and NGE pair
for all elements of arr[] of size n */
void printNGE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++) {
        next = -1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " --> " << next << endl;
    }
}

// Driver Code
int main()
{
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}


//Method 2-> 
//Uses the Stack concept
//Later it will be discussed

//Thanks!!!!!!!!!!!!!!!!!!!!!
