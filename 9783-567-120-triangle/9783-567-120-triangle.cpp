class Solution {
public:
    int solve(vector<vector<int>>& triangle, int& len, int index, int index2 ,vector<vector<int>>&dp) {
        if (index == triangle.size()) {
            return 0;
        }
        int ans = triangle[index][index2];

        if(dp[index][index2] != -1){
            return dp[index][index2];
        }
        // 2 options :
        int op1 = solve(triangle, len, index + 1, index2 , dp);
        int op2 = solve(triangle, len, index + 1, index2 + 1 , dp);

        ans += min(op1, op2);
        return dp[index][index2] = ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int len = triangle.size();
        vector<vector<int>>dp(len + 1,vector<int>(len + 1 , -1));
        int ans = solve(triangle, len, 0, 0 , dp);
        return ans;
    }
};