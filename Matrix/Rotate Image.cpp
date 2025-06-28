// T.C : O(n^2)
// S.C : O(1)

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int row = matrix.size();
        int col = matrix[0].size();

        // Transpose

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (i <= j)
                    swap(matrix[i][j], matrix[j][i]);

        for (auto &x : matrix)
            reverse(x.begin(), x.end());
    }
};

// T.C : O(n^2)
// S.C : O(n^2)

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int n = matrix.size();
        vector<vector<int>> rotate(n, vector<int>(n));
        for (int j = n - 1; j >= 0; j--)
            for (int i = 0; i < n; i++)
                rotate[i][j] = matrix[n - j - 1][i];
        matrix = rotate;
    }
};