class Solution {
public:
    int solve(string& word1, string& word2, int i, int j) {
        if (i >= word1.length()) { // base case important hai
            return word2.length() - j;
        }
        if (j >= word2.length()) {
            return word1.length() - i;
        }
        int mini = 0;
        if (word1[i] == word2[j]) {
            mini = 0 + solve(word1, word2, i + 1, j + 1);
        } else {
            // Insert
            int op1 = 1 + solve(word1, word2, i, j + 1);
            // Delete
            int op2 = 1 + solve(word1, word2, i + 1, j);
            // Replace
            int op3 = 1 + solve(word1, word2, i + 1, j + 1);

            mini = min(op1, min(op2, op3));
        }

        return mini;
    }
    int solveWithMem(string& word1, string& word2, int i, int j,
                     vector<vector<int>>& dp) {
        if (i >= word1.length()) { // base case important hai
            return word2.length() - j;
        }
        if (j >= word2.length()) {
            return word1.length() - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int mini = 0;
        if (word1[i] == word2[j]) {
            mini = 0 + solveWithMem(word1, word2, i + 1, j + 1, dp);
        } else {
            // INSERT
            int op1 = 1 + solveWithMem(word1, word2, i, j + 1, dp);
            // DELETE
            int op2 = 1 + solveWithMem(word1, word2, i + 1, j, dp);
            // REPLACE
            int op3 = 1 + solveWithMem(word1, word2, i + 1, j + 1, dp);

            mini = min(op1, min(op2, op3));
        }
        dp[i][j] = mini;

        return dp[i][j];
    }

    int solveWithTabulation(string& word1, string& word2) {
        vector<vector<int>> dp(word1.length() + 1,vector<int>(word2.length() + 1, -1));
        for (int col = 0; col <= word2.length(); col++) {
            dp[word1.length()][col] = word2.length() - col;
        }
        for (int row = 0; row <= word1.length(); row++) {
            dp[row][word2.length()] = word1.length() - row;
        }
        for(int i_index = word1.length()-1 ; i_index>=0 ;i_index--){
            for(int j_index = word2.length()-1;j_index>=0;j_index--){
                int mini = 0;
                if (word1[i_index] == word2[j_index]) {
                    mini = 0 + dp[i_index+1][j_index+1];
                } else {
                    // INSERT
                    int op1 = 1 + dp[i_index][j_index+1];
                    // DELETE
                    int op2 = 1 + dp[i_index + 1][j_index];
                    // REPLACE
                    int op3 = 1 + dp[i_index+1][j_index+1];

                    mini = min(op1, min(op2, op3));
                }
            dp[i_index][j_index] = mini;
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(),
        // -1)); int ans = solveWithMem(word1, word2, i, j, dp);
        int ans = solveWithTabulation(word1, word2);
        return ans;
    }
};