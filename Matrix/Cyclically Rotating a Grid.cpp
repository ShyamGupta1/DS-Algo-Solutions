class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (m and n)
        {
            int rot = k % (2 * (m + n) - 4);
            while (rot--)
            {
                // Perform Sigle Rotation
                int temp = grid[top][left];
                for (int i = left; i < right; i++)
                    grid[top][i] = grid[top][i + 1];
                for (int i = top; i < bottom; i++)
                    grid[i][right] = grid[i + 1][right];
                for (int i = right; i > left; i--)
                    grid[bottom][i] = grid[bottom][i - 1];
                for (int i = bottom; i > top; i--)
                    grid[i][left] = grid[i - 1][left];
                grid[top + 1][left] = temp;
            }
            left++, right--, top++, bottom--;
            m = right - left + 1, n = bottom - top + 1;
        }
        return grid;
    }
};