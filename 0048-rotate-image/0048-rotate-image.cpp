class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void mirror(vector<vector<int>>& matrix){
        
        for(int i=0;i<matrix.size();i++){ // horizontal
            reverse(matrix[i].begin(),matrix[i].end());
                
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        mirror(matrix);
        
    }
};