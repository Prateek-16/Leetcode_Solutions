class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j,
              vector<vector<int>>& memo) {
        if (i >= grid.size() || j >= grid[0].size()) {
            return INT_MAX;
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int ans = grid[i][j];
        // 2 options
        int down = solve(grid, i + 1, j, memo);
        int side = solve(grid, i, j + 1, memo);

        ans += min(down, side);

        return memo[i][j] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int i = 0;
        int j = 0;
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, i, j, memo);
    }
};