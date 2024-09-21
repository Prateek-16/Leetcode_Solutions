class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool setFirstRow = false;
        bool setFirstCol = false;
        
        for(int i = 0;i<matrix.size();i++){
            if(matrix[i][0] == 0){
                setFirstCol = true;
                break;
            }
        }
        
        for(int i = 0;i<matrix[0].size();i++){
            if(matrix[0][i] == 0){
                setFirstRow = true;
                break;
            }
        }
        
        //Using 1st Row and Column as a marker
        for(int i = 1;i<matrix.size();i++){
            for(int j = 1;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        //Using 1st Row and Col to Set 0s
        for(int i = 1;i<matrix.size();i++){
            for(int j = 1;j<matrix[0].size();j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }           
        }
        
        if(setFirstRow){
            for(int i = 0;i<matrix[0].size();i++){
                matrix[0][i] = 0;
            }
        }
        
        if(setFirstCol){
            for(int i = 0;i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }
    }
    
};