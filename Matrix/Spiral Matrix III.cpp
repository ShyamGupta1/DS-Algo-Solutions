// T.C: Time complexity: O(max(rows,cols)^2)  -> In worst case we might also move out of the matrix during traversal
// S.C: O(1) (excluding output matrix)

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {

        // create a direction vector EAST, SOUTH, WEST, NORTH
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;

        int steps = 0, dir = 0;
        ans.push_back({rStart, cStart});
        while (ans.size() < rows * cols)
        {
            if (dir == 0 or dir == 2)
                steps++;
            for (int i = 0; i < steps; i++)
            {
                rStart += direction[dir][0];
                cStart += direction[dir][1];
                if (rStart >= 0 and rStart < rows and cStart >= 0 and cStart < cols)
                    ans.push_back({rStart, cStart});
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};