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

// T.C : O(log(m*n))
// S.C : o(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Using Binary Search
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int i = mid / n, j = mid % n;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};