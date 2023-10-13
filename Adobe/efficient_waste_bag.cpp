//by Raja Bhavesh
//Difficulty Level-> Easy to Medium
//Question Link-> https://www.geeksforgeeks.org/efficient-waste-bagging/

//Approach-> Two pointer Approach
//Time Compleity-> O(NlogN)
//Space Complexity-> O(1)

// C++ code for the above approach:




#include <algorithm>
#include <iostream>
#include <vector>

int MinBags(std::vector<double>& wasteList)
{

	// Sort the waste items in ascending
	// order to facilitate efficient grouping.
	std::sort(wasteList.begin(), wasteList.end());

	// Initialize variables for start and
	// end pointers, and answer
	// (minimum number of bags required).
	int answer = 0;
	int start = 0;
	int end = wasteList.size() - 1;

	// Iterate through the list using a
	// two-pointer approach.
	while (start <= end) {
		if (start == end) {
			answer += 1;
			break;
		}

		// If the sum of weights at start
		// and end is less than or equal
		// to 3, both items can be packed
		// into the same bag.
		if (wasteList[start] + wasteList[end] <= 3) {
			start += 1;
			end -= 1;
			answer += 1;
			continue;
		}

		// If the sum of weights exceeds
		// 3, pack the current item at
		// end separately in a new bag.
		answer += 1;
		end -= 1;
	}

	// Return the answer, representing the
	// minimum number of bags needed to
	// carry all the waste items efficiently.
	return answer;
}

// Drivers code
int main()
{
	std::vector<double> wasteList
		= { 1.30, 1.40, 1.50, 1.60 };

	// Call the MinBags function and print the result
	std::cout << MinBags(wasteList) << std::endl;
	return 0;
}
