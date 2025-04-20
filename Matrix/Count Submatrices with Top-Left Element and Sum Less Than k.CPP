// T.C : O(m*n)
// S.C : O(m*n)

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {

        // PreCompute preSum in one pass
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<vector<int>> preSum = grid;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int sum = preSum[i][j];
                if (j - 1 >= 0)
                    sum += preSum[i][j - 1];
                if (i - 1 >= 0)
                    sum += preSum[i - 1][j];
                if (j - 1 >= 0 and i - 1 >= 0)
                    sum -= preSum[i - 1][j - 1];
                preSum[i][j] = sum;
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (preSum[i][j] <= k)
                    count++;
        return count;
    }
};