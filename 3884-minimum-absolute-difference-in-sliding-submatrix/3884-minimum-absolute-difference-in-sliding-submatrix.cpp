class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                // Collect all values in the current k x k submatrix
                vector<int> values;
                for (int x = 0; x < k; ++x) {
                    for (int y = 0; y < k; ++y) {
                        values.push_back(grid[i + x][j + y]);
                    }
                }

                // Sort to find minimum absolute difference between distinct values
                sort(values.begin(), values.end());
                int minDiff = INT_MAX;
                for (int d = 1; d < values.size(); ++d) {
                    if (values[d] != values[d - 1]) {
                        minDiff = min(minDiff, abs(values[d] - values[d - 1]));
                    }
                }

                // If all values are the same, minDiff will remain INT_MAX → set to 0
                ans[i][j] = (minDiff == INT_MAX) ? 0 : minDiff;
            }
        }
        return ans;
    }
};
