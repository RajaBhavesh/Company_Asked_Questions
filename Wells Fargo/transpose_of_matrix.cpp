//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link-> https://practice.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1



//Method 1->
//Run a nested loop using two integer pointers i and j for 0 <= i < N and 0 <= j < M
//Set B[i][j] equal to A[j][i]




//Time complexity: O(M x N)
//Auxiliary Space: O(M x N)


// C++ program to find 
// transpose of a matrix 
#include <bits/stdc++.h> 
using namespace std; 
#define N 4 

// This function stores transpose 
// of A[][] in B[][] 
void transpose(int A[][N], int B[][N]) 
{ 
    int i, j; 
    for (i = 0; i < N; i++) 
        for (j = 0; j < N; j++) 
            B[i][j] = A[j][i]; 
} 

// Driver code 
int main() 
{ 
    int A[N][N] = { { 1, 1, 1, 1 }, 
                    { 2, 2, 2, 2 }, 
                    { 3, 3, 3, 3 }, 
                    { 4, 4, 4, 4 } }; 

    // Note dimensions of B[][] 
    int B[N][N], i, j; 

    // Function call 
    transpose(A, B); 

    cout << "Result matrix is \n"; 
    for (i = 0; i < N; i++) { 
        for (j = 0; j < N; j++) 
            cout << " " << B[i][j]; 

        cout << "\n"; 
    } 
    return 0; 
} 



//Method 2->
//This approach works only for square matrices (i.e., – where no. of rows are equal to the number of columns). 
//This algorithm is also known as an “in-place” algorithm as it uses no extra space to solve the problem.


//Run a nested loop using two integer pointers i and j for 0 <= i < N and i+1 <= j < N
//Swap A[i][j] with A[j][i]



//Time complexity: O(Nx N)
//Auxiliary Space: O(1)

#include <bits/stdc++.h> 
using namespace std; 

#define N 4 

// Converts A[][] to its transpose 
void transpose(int A[][N]) 
{ 
    for (int i = 0; i < N; i++) 
        for (int j = i + 1; j < N; j++) 
            swap(A[i][j], A[j][i]); 
} 

int main() 
{ 
    int A[N][N] = { { 1, 1, 1, 1 }, 
                    { 2, 2, 2, 2 }, 
                    { 3, 3, 3, 3 }, 
                    { 4, 4, 4, 4 } }; 

    transpose(A); 

    printf("Modified matrix is \n"); 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            printf("%d ", A[i][j]); 
        printf("\n"); 
    } 

    return 0; 
}



//Thanks!!!!!!!!!!!!!!!!!!!!!
