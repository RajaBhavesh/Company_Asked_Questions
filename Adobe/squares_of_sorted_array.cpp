//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link-> https://www.codingninjas.com/studio/problems/squares-of-a-sorted-array_1230552?leftPanelTab=0

//Method 1-> 
//Simple solution is to first convert each array element into its square and then apply any “O(nlogn)”
// sorting algorithm to sort the array elements.
//Time Complexity-> O(NlogN)
//Space Complexity-> O(1)

// C++ program to Sort square of the numbers
// of the array
#include <bits/stdc++.h>
using namespace std;

// Function to sort an square array
void sortSquares(int arr[], int n)
{
    // First convert each array elements
    // into its square
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] * arr[i];

    // Sort an array using "sort STL function "
    sort(arr, arr + n);
}

// Driver program to test above function
int main()
{
    int arr[] = { -6, -3, -1, 2, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    sortSquares(arr, n);

    cout << "\nAfter Sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}


//Method 2-> 
//Efficient Approach
//Another efficient solution is based on the two-pointer method as the array is already sorted
// we can compare the first and last element to check which is bigger and proceed with the result. 


//C++ Code

//Time Complexity-> O(N)
//Space Complexity-> O(N)
/ CPP code for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to sort an square array
void sortSquares(vector<int>& arr, int n)
{
    int left = 0, right = n - 1;
    int result[n];
 
    // Iterate from n - 1 to 0
    for (int index = n - 1; index >= 0; index--) {
       
        // Check if abs(arr[left]) is greater
        // than arr[right]
        if (abs(arr[left]) > arr[right]) {
            result[index] = arr[left] * arr[left];
            left++;
        }
        else {
            result[index] = arr[right] * arr[right];
            right--;
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] = result[i];
}
 
// Driver Code
int main()
{
    vector<int> arr;
    arr.push_back(-6);
    arr.push_back(-3);
    arr.push_back(-1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(5);
 
    int n = 6;
 
    cout << "Before sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    sortSquares(arr, n);
    cout << endl;
    cout << "After Sort " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}


//Thanks!!!!!!!!!!!!!!!!!!!!!
