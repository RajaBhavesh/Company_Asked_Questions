//by Raja Bhavesh
//Difficulty Level-> Medium
//Question Link-> https://practice.geeksforgeeks.org/problems/rank-the-permutations2229/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//Method 1-> 
//One simple solution is to generate all the permutations in lexicographic order and store the rank of the current string. After generating a permutation, check 
//if the generated permutation is the same as the given string and return the rank of str.
//Time Complexity-> O(N*N)
//Space Complexity-> O(1)

#include <bits/stdc++.h>
using namespace std;

// Define a function to calculate the factorial of a given number using recursion
int fact(int n) {
    // Base case: if n is 0 or 1, return 1
    if(n <= 1) {
        return 1;
    }
    // Recursive case: return n times the factorial of n-1
    return n * fact(n - 1);
}

// Define a function to calculate the rank of a given string in lexicographic permutation order
int findRank(string str) {
    // Calculate the length of the input string
    int n = str.length();
    // Initialize the rank as 1
    int rank = 1;

    // Loop through each character of the string
    for(int i = 0; i < n; i++) {
        // Initialize a variable to count the number of characters less than str[i]
        int count = 0;

        // Loop through the characters after str[i]
        for(int j = i + 1; j < n; j++) {
            // If str[i] is greater than str[j], increment the count variable
            if(str[i] > str[j]) {
                count++;
            }
        }

        // Update the rank based on the count of characters less than str[i]
        // multiplied by the factorial of the number of remaining characters
        rank += count * fact(n - i - 1);
    }

    // Return the final rank of the input string
    return rank;
}

// Define the main function
int main() {
    // Define a test string
    string str = "string";
    // Call the findRank function on the test string and print the result
    cout << findRank(str) << endl;
    // Return 0 to indicate successful program completion
    return 0;
}


//Method 2-> 
//Efficient Approach
//For characters in each index, find how many lexicographically smaller strings can be formed when all the characters till that
// index are fixed. This will give the strings smaller than that and we can get the rank


//C++ Code

//Time Complexity-> O(N*N)
//Space Complexity-> O(1)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long findRank(string arr) {
        //code here
        int n=arr.size();
        long long int fact[n];
        fact[0]=1;
        for(int i=1;i<n;i++){
            fact[i]=fact[i-1]*i;
       //     cout<<fact[i]<< " ";
        }
     //   cout<<endl;
        long long int rank=0;
        for(int i=0;i<n;i++){
            long long count=0;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[i]){
                    count++;
                }
            }
           // cout<<fact[n-i-1]<<endl; 
            rank+=count*fact[n-i-1];
         //   cout<<rank<<" ";
        }
        return rank+1;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends


//Thanks!!!!!!!!!!!!!!!!!!!!!
