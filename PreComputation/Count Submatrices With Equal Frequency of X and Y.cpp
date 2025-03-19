class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> countRangeX(row, vector<int>(col, 0));
        vector<vector<int>> countRangeY(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++)
        {
            int countX = 0, countY = 0;
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 'X')
                {
                    countX++;
                    countRangeX[i][j] = countX;
                }
                else
                    countRangeX[i][j] = countX;
                if (grid[i][j] == 'Y')
                {
                    countY++;
                    countRangeY[i][j] = countY;
                }
                else
                    countRangeY[i][j] = countY;
            }
        }

        for (int j = 0; j < col; j++)
            for (int i = 1; i < row; i++)
            {
                countRangeX[i][j] += countRangeX[i - 1][j];
                countRangeY[i][j] += countRangeY[i - 1][j];
            }
        int count = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (countRangeX[i][j] != 0 and countRangeX[i][j] == countRangeY[i][j])
                    count++;

        return count;
    }
};

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<pair<int, int>>> countRange(row, vector<pair<int, int>>(col));

        for (int i = 0; i < row; i++)
        {
            int countX = 0, countY = 0;
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 'X')
                    countX++;
                if (grid[i][j] == 'Y')
                    countY++;
                countRange[i][j] = {countX, countY};
            }
        }

        for (int j = 0; j < col; j++)
            for (int i = 1; i < row; i++)
            {
                countRange[i][j].first += countRange[i - 1][j].first;
                countRange[i][j].second += countRange[i - 1][j].second;
            }
        int count = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (countRange[i][j].first != 0 and countRange[i][j].first == countRange[i][j].second)
                    count++;

        return count;
    }
};