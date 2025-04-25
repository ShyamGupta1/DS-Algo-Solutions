// T.C : O(k*m*n)
// S.C : O(m*n)

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        ans = grid;
        // int rot=k%(m*n+1);
        while (k--)
        {
            // Single Rotation
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                {
                    if (i == m - 1 and j == n - 1)
                        ans[0][0] = grid[i][j];
                    else if (j == n - 1)
                        ans[i + 1][0] = grid[i][j];
                    else
                        ans[i][j + 1] = grid[i][j];
                }
            grid = ans;
        }
        return ans;
    }
};