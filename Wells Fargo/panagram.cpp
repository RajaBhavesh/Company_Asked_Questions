//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link->https://www.hackerrank.com/challenges/pangrams/problem



//Method 1->
//Create an array of Boolean types and iterate through all the characters of the string and mark it as visited. Lowercase and Uppercase 
//are considered the same. So ‘A’ and ‘a’ are marked in index 0 and similarly ‘Z’ and ‘z’ are marked in index 25.

//After iterating through all the characters check whether all the characters are marked or not. 
//If not then return false as this is not a pangram else return true. 

//Time Complexity-> O(N)
//Space Complexity-> O(1)

string pangrams(string s) {
    bool alphabet[26]={0};
    for(int i=0;i<s.size();i++){
        if(s[i]>=65&&s[i]<=90){
            alphabet[s[i]-65]=1;
        }
        if(s[i]>=97&&s[i]<=122){
            alphabet[s[i]-97]=1;
        }
    }
    for(int i=0;i<26;i++){
        if(alphabet[i]==0){
            return "not pangram";
        }
    }
    return "pangram";
    
}


//Method 2->
//The idea to use a set is quite obvious because to check a pangram, there must be 26 alphabets no matter whether it is a lowercase or uppercase character. To check whether a alphabet is already present or not,

// the alphabets have been inserted in lowercase and the set size must be 26.

//Time Complexity-> O(N)
//Space Complexity-> O(1)

// A C++ Program to check if the given
// string is a pangram or not
#include <bits/stdc++.h>
using namespace std;

// Returns true if the string is pangram else false
bool checkPangram(string& str)
{
    // Initialize a set of characters
    set<char> set;

    for (auto ch : str) {
        // If the character is already
        // a lowercase character
        if (ch >= 'a' and ch <= 'z')
            set.insert(ch);

        // In case of a uppercase character
        if (ch >= 'A' and ch <= 'Z') {
            // convert to lowercase
            ch = tolower(ch);
            set.insert(ch);
        }
    }

    // check if the size is 26 or not
    return set.size() == 26;
}

// Driver Program to test above functions
int main()
{
    string str = "The quick brown fox jumps over the"
                " lazy dog";
    if (checkPangram(str) == true)
        cout << "It is a Pangram" << endl;
    else
        cout << "It is Not a Pangram" << endl;

    return 0;
}

// This code is contributed by Rajdeep Mallick
// (rajdeepmallick999)


//Thanks!!!!!!!!!!!!!!!!!!!!!
