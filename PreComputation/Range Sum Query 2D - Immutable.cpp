class NumMatrix
{
private:
    vector<vector<int>> matrix;

public:
    NumMatrix(vector<vector<int>> &mat)
    {
        this->matrix = mat;
        for (int i = 0; i < matrix.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[i][j] = sum + matrix[i][j];
                sum = matrix[i][j];
            }
        }
        for (int i = 0; i < matrix[0].size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < matrix.size(); j++)
            {
                matrix[j][i] = sum + matrix[j][i];
                sum = matrix[j][i];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1 == 0 && col1 == 0)
        {
            return matrix[row2][col2];
        }
        else if (row1 == 0)
        {
            return matrix[row2][col2] - matrix[row2][col1 - 1];
        }
        else if (col1 == 0)
        {
            return matrix[row2][col2] - matrix[row1 - 1][col2];
        }
        return (matrix[row2][col2] + matrix[row1 - 1][col1 - 1] - matrix[row2][col1 - 1] - matrix[row1 - 1][col2]);
    }
};