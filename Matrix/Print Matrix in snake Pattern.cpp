// T.C: O(N*N)
// S.C: O(1)

class Solution
{
public:
    // Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int>> matrix)
    {
        int i = 0, n = matrix.size();
        while (i < n)
        {
            if (i % 2 == 0)
                for (int j = 0; j < n; j++)
                    cout << matrix[i][j] << " ";
            else
                for (int j = n - 1; j >= 0; j--)
                    cout << matrix[i][j] << " ";
            i++;
        }
    }
};