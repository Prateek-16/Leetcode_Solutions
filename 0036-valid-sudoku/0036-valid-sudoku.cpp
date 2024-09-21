class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rowCheck[9][9] = {0};
        int colCheck[9][9] = {0};
        int smallBoxCheck[9][9] = {0};
        
        
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                char currChar = board[i][j];
                if(currChar == '.'){
                    continue;
                } 
                
                //Since this currChar is btw 1 to 9 we will treat it as index btw 0 to 8
                int index = currChar - '0' - 1;
                int smallboxIndex = (i / 3) * 3 + (j / 3);  //A unique index for each smaller box
                
                if(rowCheck[i][index] || colCheck[index][j] || smallBoxCheck[smallboxIndex][index]){
                    return false;
                }
                rowCheck[i][index] = colCheck[index][j] = smallBoxCheck[smallboxIndex][index] = 1;
            }
        }
        return true;
        
    }
};