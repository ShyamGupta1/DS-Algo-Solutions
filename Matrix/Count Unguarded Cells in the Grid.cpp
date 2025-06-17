class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> dir = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        vector<vector<int>> grid(m, vector<int>(n, 0));
        // Mark Guards
        for (auto x : guards)
            grid[x[0]][x[1]] = 2;
        // Mark Walls
        for (auto x : walls)
            grid[x[0]][x[1]] = 2;
        // Traverse grid and mark all guarded blocks

        // for(auto x:grid){cout<<endl;for(auto y:x) cout<<y<<" ";}
        for (auto x : guards)
        {
            int count = 3, i = x[0], j = x[1];
            while (count >= 0)
            {
                int newX = i + dir[count][0], newY = j + dir[count][1];
                while (newX >= 0 and newX < m and newY >= 0 and newY < n and grid[newX][newY] != 2)
                {
                    grid[newX][newY] = 1;
                    newX += dir[count][0], newY += dir[count][1];
                }
                count--;
            }
        }
        int ans = 0;
        for (auto x : grid)
            for (auto y : x)
                if (!y)
                    ans++;
        return ans;
    }
};