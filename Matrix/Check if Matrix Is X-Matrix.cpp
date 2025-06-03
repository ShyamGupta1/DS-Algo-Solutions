// T.C : O(N^2)
// S.C : O(1)

class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        // Check Diagonals
        int i = 0, j = 0, n = grid.size();
        while (i < n)
        {
            if (!grid[i][j])
                return false;
            if (!grid[i][n - j - 1])
                return false;
            i++;
            j++;
        }
        // check other elements
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                if (i == j or i == (n - j - 1))
                    continue;
                else if (grid[i][j])
                    return false;
            }
        return true;
    }
};