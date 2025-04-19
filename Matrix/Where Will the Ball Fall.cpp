// T.C : O(M*N)
// S.C : O(N)

class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {

        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            int mid = i, left = mid - 1, right = mid + 1, row = 0;
            while (row < m)
            {
                if (mid == n - 1 and grid[row][mid] == 1)
                    break;
                if (mid == 0 and grid[row][mid] == -1)
                    break;
                if (grid[row][mid] == 1 and grid[row][right] == -1)
                    break;
                if (grid[row][mid] == -1 and grid[row][left] == 1)
                    break;
                mid += grid[row][mid];
                left = mid - 1, right = mid + 1;
                row++;
            }
            if (row == m)
                ans[i] = mid;
        }
        return ans;
    }
};