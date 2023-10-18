//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link-> https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article



//Method 1-> Brute Force Approach
//We use two nested loops. Outer one traverse in arr2 of size m and at each element it searches in the arr1 of size n

//Time Complexity-> O(m*n)
//Space Complexity-> O(1)
// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>

/* Return 1 if arr2[] is a subset of
arr1[] */
bool isSubset(int arr1[], int arr2[], int m, int n)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }

        /* If the above inner loop was
        not broken at all then arr2[i]
        is not present in arr1[] */
        if (j == m)
            return 0;
    }

    /* If we reach here then all
    elements of arr2[] are present
    in arr1[] */
    return 1;
}



//Method 2-> Using Sorting and Binary Search
//The idea is to sort the given array arr1[], and then for each element in arr2[] do a binary search for it in sorted arr1[].
// If the element is not found then return 0. If all elements are present then return 1.

//Time Complexity-> O(nlogn)
//Space Complexity-> O(1)

// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
using namespace std;

/* Function prototypes */
void quickSort(int* arr, int si, int ei);
int binarySearch(int arr[], int low, int high, int x);

/* Return 1 if arr2[] is a subset of arr1[] */
bool isSubset(int arr1[], int arr2[], int m, int n)
{
    int i = 0;

    quickSort(arr1, 0, m - 1);
    for (i = 0; i < n; i++) {
        if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
            return 0;
    }

    /* If we reach here then all elements
    of arr2[] are present in arr1[] */
    return 1;
}

/* FOLLOWING FUNCTIONS ARE ONLY FOR
    SEARCHING AND SORTING PURPOSE */
/* Standard Binary Search function*/
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        /*low + (high - low)/2;*/
        int mid = (low + high) / 2;

        /* Check if arr[mid] is the first
        occurrence of x. arr[mid] is first
        occurrence if x is one of the following
        is true:
        (i) mid == 0 and arr[mid] == x
        (ii) arr[mid-1] < x and arr[mid] == x */
        if ((mid == 0 || x > arr[mid - 1])
            && (arr[mid] == x))
            return mid;
        else if (x > arr[mid])
            return binarySearch(arr, (mid + 1), high, x);
        else
            return binarySearch(arr, low, (mid - 1), x);
    }
    return -1;
}

void exchange(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);
    int j;

    for (j = si; j <= ei - 1; j++) {
        if (A[j] <= x) {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange(&A[i + 1], &A[ei]);
    return (i + 1);
}

/* Implementation of Quick Sort
A[] --> Array to be sorted
si --> Starting index
ei --> Ending index
*/
void quickSort(int A[], int si, int ei)
{
    int pi; /* Partitioning index */
    if (si < ei) {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}

/*Driver code */
int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubset(arr1, arr2, m, n))
        cout << "arr2[] is subset of arr1[] ";
    else
        cout << "arr2[] is not a subset of arr1[] ";

    return 0;
}


//Method 3->
//Using Set concept
//In this approach we declare a set and now firstly store the values of arr1 into this set
//Int he nest step we intialise a variable say var1 and in this we store the size of set
//now we again do the same storing value of arr2 n the set and again storing the now set size to var2
//and if var1==var2 that means it is subset else not

//Note-> This method works fine if there are no duplicates

//Time Complexity-> O(n+m)
//Space Complexity-> O(n+m)

// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
using namespace std;

/* Function prototypes */
void quickSort(int* arr, int si, int ei);
int binarySearch(int arr[], int low, int high, int x);

/* Return 1 if arr2[] is a subset of arr1[] */
bool isSubset(int arr1[], int arr2[], int m, int n)
{
    int i = 0;

    quickSort(arr1, 0, m - 1);
    for (i = 0; i < n; i++) {
        if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
            return 0;
    }

    /* If we reach here then all elements
    of arr2[] are present in arr1[] */
    return 1;
}

/* FOLLOWING FUNCTIONS ARE ONLY FOR
    SEARCHING AND SORTING PURPOSE */
/* Standard Binary Search function*/
int binarySearch(int arr[], int low, int high, int x)
{
    if (high >= low) {
        /*low + (high - low)/2;*/
        int mid = (low + high) / 2;

        /* Check if arr[mid] is the first
        occurrence of x. arr[mid] is first
        occurrence if x is one of the following
        is true:
        (i) mid == 0 and arr[mid] == x
        (ii) arr[mid-1] < x and arr[mid] == x */
        if ((mid == 0 || x > arr[mid - 1])
            && (arr[mid] == x))
            return mid;
        else if (x > arr[mid])
            return binarySearch(arr, (mid + 1), high, x);
        else
            return binarySearch(arr, low, (mid - 1), x);
    }
    return -1;
}

void exchange(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);
    int j;

    for (j = si; j <= ei - 1; j++) {
        if (A[j] <= x) {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange(&A[i + 1], &A[ei]);
    return (i + 1);
}

/* Implementation of Quick Sort
A[] --> Array to be sorted
si --> Starting index
ei --> Ending index
*/
void quickSort(int A[], int si, int ei)
{
    int pi; /* Partitioning index */
    if (si < ei) {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}

/*Driver code */
int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubset(arr1, arr2, m, n))
        cout << "arr2[] is subset of arr1[] ";
    else
        cout << "arr2[] is not a subset of arr1[] ";

    return 0;
}

//Method 4-> Best and Correct Approach
//Able to handle the duplicate cases also

//The idea is to store the frequency of the elements present in the first array, then look for the elements present in arr2[] in the frequency array.
// As no new elements are found in arr2[] hence is the subset.

//Time Complexity-> O(m)
//Space Complexity-> O(m)

// C++ program to find whether an array
// is subset of another array
#include <bits/stdc++.h>
using namespace std;
/* Return true if arr2[] is a subset of arr1[] */

bool isSubset(int arr1[], int m, int arr2[], int n)
{
    // Create a Frequency Table using STL
    map<int, int> frequency;

    // Increase the frequency of each element
    // in the frequency table.
    for (int i = 0; i < m; i++) {
        frequency[arr1[i]]++;
    }
    // Decrease the frequency if the
    // element was found in the frequency
    // table with the frequency more than 0.
    // else return 0 and if loop is
    // completed return 1.
    for (int i = 0; i < n; i++) {
        if (frequency[arr2[i]] > 0)
            frequency[arr2[i]]--;
        else {
            return false;
        }
    }
    return true;
}

// Driver Code
int main()
{
    int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubset(arr1, m, arr2, n))
        cout << "arr2[] is subset of arr1[] "
            << "\n";
    else
        cout << "arr2[] is not a subset of arr1[] "
            << "\n";
    return 0;
}




//Same concept can be done by declaring hash array

string isSubset(int a1[], int a2[], int n, int m) {
    int hash[1000000]={0};
    for(int i=0;i<n;i++){
        hash[a1[i]]++;
    }
    for(int i=0;i<m;i++){
        if(hash[a2[i]]==0){
            return "No";
        }
        else{
            hash[a2[i]]--;
        }
    }
    return "Yes";
}



//Thanks!!!!!!!!!!!!!!!!!!!!!
