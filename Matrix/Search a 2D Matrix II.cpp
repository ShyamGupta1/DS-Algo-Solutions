// Approach 1: (Binary Search)
// T.C : O(mlogn)
// S.C : O(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            int low = 0, high = n - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] == target)
                    return true;
                if (matrix[i][mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};

// Approach 2 (Optimised)
// T.C : O(M+N)
// S.C : O(1)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = n - 1;
        while (start >= 0 and start < m and end >= 0 and end < n)
        {
            if (matrix[start][end] > target)
                end--;
            else if (matrix[start][end] < target)
                start++;
            else
                return true;
        }
        return false;
    }
};
