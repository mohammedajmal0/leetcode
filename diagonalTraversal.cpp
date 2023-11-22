// 498. Diagonal Traverse
// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        bool up=true;
        vector<int> ans;
        int row=0,col=0,i=0;
        while(row<m && col<n){
            if(up){
                while(row>0 && col<n-1){
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                ans.push_back(mat[row][col]);
                if(col==n-1){
                    row++;
                }
                else{
                    col++;
                }
            }
            else{
                while(col>0 && row<m-1){
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                ans.push_back(mat[row][col]);
                if(row==m-1){
                    col++;
                }
                else{
                    row++;
                }
            }
            up=!up;
        }
        return ans;
    }
};