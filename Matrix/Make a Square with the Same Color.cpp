// T.C: O(m*n)
// S.C: O(1)

class Solution
{
public:
    bool canMakeSquare(vector<vector<char>> &grid)
    {

        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                int countW = 0;
                if (grid[i][j] == 'W')
                    countW++;
                if (grid[i + 1][j] == 'W')
                    countW++;
                if (grid[i][j + 1] == 'W')
                    countW++;
                if (grid[i + 1][j + 1] == 'W')
                    countW++;
                if (countW == 3 or countW == 1 or countW == 0 or countW == 4)
                    return true;
            }
        }
        return false;
    }
};