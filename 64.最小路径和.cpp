/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int distance = 0;

        vector<vector<int>> dp(grid);
        dp[0][0] = grid[0][0];
        for(int i=1; i<grid.size(); i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i=1; i<grid[0].size(); i++)
            dp[0][i] = dp[0][i-1] + grid[0][i];

        for(int i=1; i<grid.size(); i++) {
            for(int j=1; j<grid[0].size(); j++) {
                int min = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                dp[i][j] = min + grid[i][j];
            }
        }

        distance = dp[grid.size()-1][grid[0].size()-1];
        return distance;
    }
};
// @lc code=end

