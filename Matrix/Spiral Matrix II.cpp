// T.C: O(n*n)
// S.C: O(1) (excluding output matrix)

// Approach 1
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        vector<vector<int>> nagin(n, vector<int>(n, 0));

        int top = 0;
        int bottom = nagin.size() - 1;
        int left = 0;
        int right = nagin[0].size() - 1;
        int num = 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
                nagin[top][i] = num++;
            top++;
            if (top > bottom)
                break;

            for (int i = top; i <= bottom; i++)
                nagin[i][right] = num++;
            right--;
            if (left > right)
                break;

            for (int i = right; i >= left; i--)
                nagin[bottom][i] = num++;
            bottom--;
            if (bottom < top)
                break;

            for (int i = bottom; i >= top; i--)
                nagin[i][left] = num++;
            left++;
        }
        return nagin;
    }
};

// Approach 2
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        vector<vector<int>> result(n, vector<int>(n, 0));
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Direction -> EAST SOUTH WEST NORTH
        int start = 0, count = 0, steps = 0, i = 0, j = -1, dir = 0;
        while (count < n * n)
        {
            if (dir == 1 or dir == 3)
                steps++;
            for (int k = 0; k < n - steps; k++)
            {
                i += direction[dir][0];
                j += direction[dir][1];
                if (i >= 0 and i < n and j >= 0 and j < n)
                    result[i][j] = ++count;
            }
            dir = (dir + 1) % 4;
        }
        return result;
    }
};