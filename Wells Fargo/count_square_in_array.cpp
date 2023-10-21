//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link->https://www.geeksforgeeks.org/count-array-elements-whose-perfect-squares-are-present-in-the-given-array/



//Method 1->
//Initialize a variable, say, count, to store the required count.
//Traverse the array and for each and every array element, perform the following operations:
//Traverse the array and search if the square of the current element is present in the array.
//If the square found increment the count.
//Print count as the answer.


//Time Complexity-> O(N^N)
//Space Complexity-> O(1)
// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the count of elements whose
// squares are already present int the array
void countSquares(int arr[], int N)
{
    // Stores the required count
    int count = 0;

    // Traverse the array
    for (int i = 0; i < N; i++) {

        // Square of the element
        int square = arr[i] * arr[i];

        // Traverse the array
        for (int j = 0; j < N; j++) {

            // Check whether the value
            // is equal to square
            if (arr[j] == square) {

                // Increment count
                count = count + 1;
            }
        }
    }

    // Print the count
    cout << count;
}

// Driver Code
int main()
{
    // Given array
    int arr[] = { 2, 4, 5, 20, 16 };

    // Size of the array
    int N = sizeof(arr) / sizeof(arr[0]);

    countSquares(arr, N);

    return 0;
}




//Method 2->
//The optimal idea is to use unordered_map to keep the count of visited elements and update the variable count accordingly
//Initialize a Map to store the frequency of array elements and initialize a variable, say, count.
//Traverse the array and for each element, increment its count in the Map.
//Again traverse the array and for each element check for the frequency of the square of the element in the map and add it to the variable count.
//Print count as the number of elements whose square is already present in the array.


//Time Complexity-> O(N)
//Space Complexity-> O(1)

/// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the count of elements whose
// squares is already present int the array
int countSquares(int arr[], int N)
{
    // Stores the count of array elements
    int count = 0;

    // Stores frequency of visited elements
    unordered_map<int, int> m;

    // Traverse the array
    for (int i = 0; i < N; i++) {
        m[arr[i]] = m[arr[i]] + 1;
    }

    for (int i = 0; i < N; i++) {

        // Square of the element
        int square = arr[i] * arr[i];

        // Update the count
        count += m[square];
    }

    // Print the count
    cout << count;
}

// Driver Code
int main()
{
    // Given array
    int arr[] = { 2, 4, 5, 20, 16 };

    // Size of the array
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    countSquares(arr, N);

    return 0;
}



//Thanks!!!!!!!!!!!!!!!!!!!!!
