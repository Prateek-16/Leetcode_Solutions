class Solution {
public:
    int solveMemo(int i, int j, vector<vector<char>>& matrix,
              vector<vector<int>>& dp) {
        if (i >= matrix.size() || j >= matrix[0].size() ||
            matrix[i][j] == '0') {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // 3 conditions
        int right = solveMemo(i, j + 1, matrix, dp);
        int diagonal = solveMemo(i + 1, j + 1, matrix, dp);
        int down = solveMemo(i + 1, j, matrix, dp);
        dp[i][j] = min({right, diagonal, down}) + 1;
        return dp[i][j];
    }
    int solveTab(vector<vector<char>>& matrix,vector<vector<int>>& dp){
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        for(int i = row - 1 ; i >= 0 ; i--){
            for(int j = col - 1 ; j >= 0 ; j--){
                int right = dp[i][j + 1];
                int down = dp[i + 1][j];
                int diagonal = dp[i + 1][j + 1];
                dp[i][j] = matrix[i][j] == '1' ? min({right , down , diagonal}) + 1 : 0;
                maxi = max(maxi , dp[i][j]);
            }
        }
        return maxi;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        // int maxi = 0;
        vector<vector<int>> dp(matrix.size() + 1,
                               vector<int>(matrix[0].size() + 1, 0));
        // for (int i = 0; i < matrix.size(); i++) {
        //     for (int j = 0; j < matrix[0].size(); j++) {
        //         maxi = max(maxi, solveMemo(i, j, matrix, dp));
        //     }
        // }
        int maxi = solveTab(matrix, dp);
        return maxi * maxi;
    }
};