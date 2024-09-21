class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        int firstRow=0;
        int lastRow=matrix.size()-1;
        
        int firstCol=0;
        int lastCol=matrix[0].size()-1;
        
        int Total_elements=(lastRow+1)*(lastCol+1);
        int count=0;
        
        while(count<Total_elements){
            for(int i=firstCol;i<=lastCol && count<Total_elements;i++){
                ans.push_back(matrix[firstRow][i]);
                count++;
            }
            firstRow++;
            
            for(int i=firstRow;i<=lastRow && count<Total_elements;i++){
                ans.push_back(matrix[i][lastCol]);
                count++; 
            }
            lastCol--;
            
            for(int i=lastCol;i>=firstCol && count<Total_elements;i--){
                ans.push_back(matrix[lastRow][i]);
                count++;
            }
            lastRow--;
            
            for(int i=lastRow;i>=firstRow && count<Total_elements;i--){
                ans.push_back(matrix[i][firstCol]);
                count++;
            }
            firstCol++;
        }
        return ans;
    }
};