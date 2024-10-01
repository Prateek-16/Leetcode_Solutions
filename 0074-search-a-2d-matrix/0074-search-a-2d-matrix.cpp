class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int n=rows*cols;
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int row_index = mid/cols;
            int col_index = mid%cols;
            int cur_element=matrix[row_index][col_index];
            if (cur_element==target){
                return true;
                }
            else if(cur_element>target){
                e=mid-1;
                }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return false;
        
    }
};