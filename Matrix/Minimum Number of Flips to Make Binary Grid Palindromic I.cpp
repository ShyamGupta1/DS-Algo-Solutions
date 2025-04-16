// T.C : O(M∗N)
// S.C : O(1)

class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        int rowFlips = 0, colFlips = 0;
        int m = grid.size(), n = grid[0].size();

        for (auto x : grid)
        {
            int i = 0, j = n - 1;
            while (i < j)
            {
                if (x[i] != x[j])
                    rowFlips++;
                i++;
                j--;
            }
        }
        for (int j = 0; j < n; j++)
        {
            int first = 0, last = m - 1;
            while (first < last)
            {
                if (grid[first][j] != grid[last][j])
                    colFlips++;
                first++;
                last--;
            }
        }
        return min(rowFlips, colFlips);
    }
};