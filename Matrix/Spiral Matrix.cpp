// T.C: O(m*n)
// S.C: O(1) (excluding output vector)

// Approach 1
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> ans;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
                ans.emplace_back(matrix[top][i]);
            top++;
            if (top > bottom)
                break;

            for (int i = top; i <= bottom; i++)
                ans.emplace_back(matrix[i][right]);
            right--;
            if (right < left)
                break;

            for (int i = right; i >= left; i--)
                ans.emplace_back(matrix[bottom][i]);
            bottom--;
            if (top > bottom)
                break;

            for (int i = bottom; i >= top; i--)
                ans.emplace_back(matrix[i][left]);
            left++;
        }
        return ans;
    }
};

// Approach 2
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        // Directions -> EAST, SOUTH, WEST, NORTH
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int steps = 0, dir = 0, i = 0, j = -1, val = 0;
        while (ans.size() < m * n)
        {
            if (dir == 1 or dir == 3)
                steps++;
            if (dir == 0 or dir == 2)
                val = n - steps;
            else
                val = m - steps;
            for (int k = 0; k < val; k++)
            {
                i += direction[dir][0];
                j += direction[dir][1];
                if (i >= 0 and i < m and j >= 0 and j < n)
                    ans.push_back(matrix[i][j]);
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};