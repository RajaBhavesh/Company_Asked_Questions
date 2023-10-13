//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link-> https://www.geeksforgeeks.org/decode-the-secret-heist-code/

//Method 1-> 
//The idea is to iterate through the string “word” and whenever we get a character that is also present in the “code” we will add it to the “decoded” string. After the iteration,
// if the decoded string comes exactly the same as the code then we will return “Yes” otherwise “No”.

//Time Complexity-> O(N)
//Space Complexity-> O(N)



// C++ code for the above approach:
#include <iostream>
#include <string>
 
using namespace std;
 
// Function to decode the word based
// on the provided code
string decoding(string word, string code)
{
    string decoded = "";
 
    // Iterate through each character
    // in the word
    for (char i : word) {
 
        // Check if the character is
        // present in the code
        if (code.find(i) != string::npos) {
 
            // Add the character to
            // the decoded string
            decoded += i;
        }
    }
 
    // Check if the decoded string is
    // equal to the code
    if (decoded == code) {
 
        // Return "YES" if the decoded string
        // matches the code
        return "YES";
    }
    else {
 
        // Return "NO" if the decoded string
        // does not match the code
        return "NO";
    }
}
 
// Drivers code
int main()
{
 
    // Input word and code
    string word = "bhbalcbdkqgegr";
    string code = "hacker";
 
    // Call the decoding function
    // and print the result
    cout << decoding(word, code) << endl;
 
    return 0;
}



//Method 2-> 
//Efficient Approach
//To solve the problem using Two Pointers follow the below idea:
//In place of storing the value that matches the “code,” we will use a second pointer which will be shifted as we iterate through 
//the “word” string until we reach the end of “word” or “code”.


//C++ Code

//Time Complexity-> O(N)
//Space Complexity-> O(1)

#include <iostream>
#include <string>

using namespace std;

string decoding(string word, string code) {
    int word_index = 0; // Index for iterating through the word
    int code_index = 0; // Index for iterating through the code

    // Iterate until we reach the end of either the word or the code
    while (word_index < word.length() && code_index < code.length()) {
        // If the current characters in word and code match, move both pointers forward
        if (word[word_index] == code[code_index]) {
            word_index++;
            code_index++;
        } else {
            // If the characters don't match, move only the word pointer forward
            word_index++;
        }
    }

    // Check if we have reached the end of the word
    if (word_index == word.length()) {
        // Check if we have reached the end of the code
        if (code_index == code.length()) {
            // Return "YES" if all characters in the word are found in the code
            return "YES";
        } else {
            // Return "NO" if the code has additional characters
            return "NO";
        }
    } else {
        // If we are not at the end of the word, iterate through the remaining characters in the word
        while (word_index < word.length()) {
            // If any character in the word is found in the code, return "NO"
            if (code.find(word[word_index]) != string::npos) {
                return "NO";
            }
            word_index++;
        }

        // Return "YES" if no character in the word is found in the code
        // after we get the code string in the first while loop
        return "YES";
    }
}

// Driver Code
int main() {
    string word = "bhbalcbdkqgegr";
    string code = "hacker";
    cout << decoding(word, code) << endl;

    return 0;
}



//Thanks!!!!!!!!!!!!!!!!!!!!!
