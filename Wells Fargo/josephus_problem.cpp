//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link-> https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

//Method 1->
//Brute Force
//If we look at the question, it says that the people are playing the game on a round table. That means, A Circular Linked List can be used to visualize the round table. We store 1,2,3,4,.......,n as the nodes of our List and go on deleting every kth node that we encounter. 
//When we are left with only 1 node i.e. the head node, it is our WINNER




//Time complexity: O(N*k)
//Auxiliary Space: O(N)

class Solution {
public:
    int helper(ListNode *head,int k){
        ListNode *temp=head;  //For traversing through the List and delete every kth Node 
        while(head->next!=head){   //Till the last Node remains in the list i.e. the winner
            ListNode *pre=NULL;
            for(int i=1; i<k; i++){
                pre=temp;
                temp=temp->next;
            }
            //Deletion procedure
            if(temp==head)
                head=head->next;
            pre->next=temp->next;
            delete(temp);
            temp=pre->next;
        }
        //The last node remaining becomes the head of the Circular Linked List i.e. Winner
        return head->val;
    }
    int findTheWinner(int n, int k) {
        if(k==1)
            return n;
        //Designing Circular Linked List for Node 1,2,3,4,.....,n
        ListNode *head=NULL,*tail=NULL;
        for(int i=1; i<=n; i++){
            ListNode *node=new ListNode(i);
            if(head==NULL)
                head=tail=node;
            else{
                tail->next=node;
                tail=node;
            }
            tail->next=head;
        }
        //Helper function will eliminate the nodes and give us the winner
        return helper(head,k);
    }
};





//Method 2->
//Recursive Approach

//If you observe, you can see that we are doing the same activity again and again i.e. deleting every kth element we encounter. Therefore, we can think towards the recursive approach also.
//Intution : If I have the winner for 'n-1' and 'k'. I can find the winner for 'n' and 'k' by moving on to the next kth person (i.e. f(n) = f(n-1)+k).
// Keeping in mind that they are sitting on a round table we have to rotate also (i.e. f(n) = (f(n-1)+k)%n).

//Time complexity: O(N)
//Auxiliary Space: O(N)
class Solution {
public:
    int helper(int n,int k){
        if(n==1)
            return 0;
        return (helper(n-1,k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   //+1 is for converting 0-based indexing to 1-based indexing
    }
};


//Method-3>
//Iterative Approach

//We can simply convert our Recursive Solution into Iterative Solution. This will bring no change in the Time Complexity but the Space Complexity will be optimised from O(n) to O(1). 
//Our intution remains the same and looks very much similar to our Recursive Solution. 

//Time Complexity-> O(N)
//Space Complexity-> O(1)

class Solution {
public:
    int helper(int n,int k){
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   //+1 is for conterting 0-based indexing to 1-based indexing
    }
};



//Thanks!!!!!!!!!!!!!!!!!!!!!
