class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> rowSum(m, 0);
        long long total = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i] += grid[i][j];
            }
            total += rowSum[i];
        }

        // Try horizontal cut
        long long topSum = 0;
        for (int i = 0; i < m - 1; ++i) {
            topSum += rowSum[i];
            if (topSum * 2 == total) return true;
        }

        vector<long long> colSum(n, 0);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                colSum[j] += grid[i][j];
            }
        }

        // Try vertical cut
        long long leftSum = 0;
        for (int j = 0; j < n - 1; ++j) {
            leftSum += colSum[j];
            if (leftSum * 2 == total) return true;
        }

        return false;
    }
};