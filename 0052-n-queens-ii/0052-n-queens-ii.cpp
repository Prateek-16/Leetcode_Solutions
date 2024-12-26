class Solution {
public:
    void solve(int col_index , int n , vector<string>&board , vector<int>&horizontal , vector<int>&minor_diagonal , vector<int>& major_diagonal , int& ans){
        if(col_index==n){
            ans++;
            return;
        }
        
        for(int i = 0; i < n ; i++){
            //i is for rows
            if(horizontal[i] == 0 && minor_diagonal[i + col_index] == 0 && major_diagonal[(n - 1) + (i - col_index)] == 0){
                
                board[i][col_index] = 'Q';
                horizontal[i] = 1;
                minor_diagonal[i + col_index] = 1;
                major_diagonal[(n - 1) + (i - col_index)] = 1;
                
                solve(col_index + 1 , n , board , horizontal , minor_diagonal , major_diagonal , ans);
                
                board[i][col_index] = '.';
                horizontal[i] = 0;
                minor_diagonal[i + col_index] = 0;
                major_diagonal[(n - 1) + (i - col_index)] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        int ans = 0;
        vector<string>board(n);
        string s(n, '.');
        for(int i = 0 ; i < n ; i++){
            board[i] = s;
        }
        vector<int>horizontal(n, 0);
        vector<int>minor_diagonal(2*n - 1 , 0);
        vector<int>major_diagonal(2*n - 1 , 0);
        solve(0 , n , board , horizontal , minor_diagonal , major_diagonal , ans);
        return ans;
    }
};