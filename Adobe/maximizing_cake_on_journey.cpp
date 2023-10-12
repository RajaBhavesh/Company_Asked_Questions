//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link-> https://www.geeksforgeeks.org/maximizing-cakes-on-a-journey/

//Time Complexity-> O(1)
//Space Complexity-> O(1)


// C++ code for the above approach:
#include <iostream>;
using namespace std;

// Function to calculate the maximum
// number of cakes
int maxCakes(int N, int K, int L)
{

	// Calculate the number of cakes we can buy
	int BuyCakes = K - L;

	// Check the availability of cakes when
	// we have to sell
	if (N + BuyCakes < L) {

		// Return -1 if we have a shortage of
		// cakes when we have to sell
		return -1;
	}
	else {

		// Return the maximum number of cakes
		// we will have at a place
		return BuyCakes + N;
	}
}

// Drivers code
int main()
{
	int N = 5;
	int K = 3;
	int L = 1;

	// Call the maxCakes function and
	// print the result
	cout << maxCakes(N, K, L) << endl;

	return 0;
}

//Thanks !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
