class Solution {
public:
    bool dfs(vector<vector<char>>& board , int i , int j , string word , int index){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]){
            return false;
        }
        
        if(index >= word.size() - 1){
            return true;
        }
        bool ans = false;
        
        board[i][j] = '#';
        ans |= dfs(board , i + 1 , j , word , index + 1);
        ans |= dfs(board , i - 1 , j , word , index + 1);
        ans |= dfs(board , i , j + 1 , word , index + 1);
        ans |= dfs(board , i , j - 1 , word , index + 1);
        
        board[i][j] = word[index];
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i = 0;i<board.size();i++){
            for(int j = 0; j < board[0].size();j++){
                if(board[i][j] == word[0]){
                    ans |= dfs(board , i , j , word , 0);
                }
            }
        }
        return ans;  
    }
};