// T.C : O(M + N)
// S.C : O(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i >= 0 and i < m and j >= 0 and j < n)
        {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                j -= 1;
            else if (matrix[i][j] < target)
                i += 1;
        }
        return false;
    }
};