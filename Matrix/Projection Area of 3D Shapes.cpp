class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {

        int area = 0, n = grid.size();
        // xy plane
        for (auto x : grid)
            for (auto y : x)
                if (y)
                    area++;
        // xz plane
        for (auto x : grid)
            area += (*max_element(x.begin(), x.end()));
        // yz plane
        for (int j = 0; j < n; j++)
        {
            int maxi = -1;
            for (int i = 0; i < n; i++)
                maxi = max(grid[i][j], maxi);
            area += maxi;
        }
        return area;
    }
};