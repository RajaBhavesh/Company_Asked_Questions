//by Raja Bhavesh
//Difficulty Level-> Easy
//Question Link-> https://leetcode.com/problems/search-a-2d-matrix/description/

//Method 1-> 
//Just traverse the whole matrix element one by one using two nested loops

//Time Complexity-> O(N*M)
//Space Complexity-> O(1)




bool searchMatrix(vector<vector<int>>& mat, int target) {
        int M=mat.size();
    int N=mat[0].size();
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(mat[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }

//Method 2-> 

//C++ Code

//Time Complexity-> O(log(N*M))
//Space Complexity-> O(1)

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start=0;
        int col=matrix[0].size();
        int end=matrix.size()*matrix[0].size()-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            int row=mid/col;
            int colo=mid%col;
            if(matrix[row][colo]==target){
                return true;
            }
            else if(matrix[row][colo]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        return false;
    }

//Thanks!!!!!!!!!!!!!!!!!!!!!
