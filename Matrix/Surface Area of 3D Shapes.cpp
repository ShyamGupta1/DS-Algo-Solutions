// T.C : O(N^2)
// S.C : O(1)

class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {

        int n = grid.size(), area = 0;

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                    area += 2;
                for (auto x : dir)
                {
                    int newI = i + x[0], newJ = j + x[1];
                    if (newI >= 0 and newI < n and newJ >= 0 and newJ < n and grid[newI][newJ] > grid[i][j])
                        area += (grid[newI][newJ] - grid[i][j]);
                    else if (newI >= 0 and newI < n and newJ >= 0 and newJ < n and grid[i][j] >= grid[newI][newJ])
                        continue;
                    else
                        area += grid[i][j];
                    cout << area << " ";
                }
                cout << endl;
            }
        return area;
    }
};