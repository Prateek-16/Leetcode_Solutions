class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& obstacleGrid,
              vector<vector<int>>& dp) {
        // base Case
        if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size() ||
            obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // 2 options:
        dp[i][j] = solve(i + 1, j, obstacleGrid, dp) +
                   solve(i, j + 1, obstacleGrid, dp);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size() + 1,
                               vector<int>(obstacleGrid[0].size() + 1, -1));
        return solve(0, 0, obstacleGrid, dp);
    }
};