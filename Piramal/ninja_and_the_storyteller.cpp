//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link-> https://www.codingninjas.com/studio/problems/ninja-and-the-storyteller_1264947?leftPanelTab=0
//Method 1-> 

//Time Complexity-> O(N)
//Space Complexity-> O(1)
#include <bits/stdc++.h> 
int countStories(int x, int y, int z)
{ 
     // Finding the number of paid stories.
    int paidStories = z / y;

    int freeStories = 0;

    // Initializing the count of stories whose free story has not been claimed.
    int storyCount = paidStories;

    while (storyCount >= x)
    {
        // Finding the new stories and updating the total free stories.
        int newStories = storyCount / x;
        freeStories += newStories;

        int storiesLeft = storyCount % x;

        // Updating the storyCount variable for next iteration.
        storyCount = newStories + storiesLeft;
    }

    // Returning the final answer.
    return paidStories + freeStories;
}







//Thanks!!!!!!!!!!!!!!!!!!!!!
