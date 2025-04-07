// Brute Force
// T.C : O(n^3)
// S.C : O(1)

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {

        int count = 0;
        int m = grid.size(), n = grid[0].size();
        int i, j, p, q;
        for (i = 0; i < m; i++)
            for (p = 0; p < n; p++)
            {
                for (q = 0; q < m; q++)
                    if (grid[i][q] != grid[q][p])
                        break;
                if (q == m)
                    count++;
            }
        return count;
    }
};

// Optimised (Hashmap)
// T.C : O(n^2)
// S.C : O(n)

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {

        int count = 0;
        map<vector<int>, int> mp;
        for (auto x : grid)
            mp[x]++;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                if (i <= j)
                    swap(grid[i][j], grid[j][i]);
        for (auto x : grid)
            if (mp.find(x) != mp.end())
                count += mp[x];
        return count;
    }
};