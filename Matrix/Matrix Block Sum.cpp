// T.C : O(M∗N)
// S.C : O(1) (Excluding Output Matrix)

class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {

        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                mat[i][j] += mat[i][j - 1];
        for (int j = 0; j < n; j++)
            for (int i = 1; i < m; i++)
                mat[i][j] += mat[i - 1][j];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int r1 = max(0, i - k), c1 = max(0, j - k), r2 = min(i + k, m - 1), c2 = min(j + k, n - 1);
                int ans = mat[r2][c2];
                if (c1 - 1 >= 0)
                    ans -= mat[r2][c1 - 1];
                if (r1 - 1 >= 0)
                    ans -= mat[r1 - 1][c2];
                if (r1 - 1 >= 0 and c1 - 1 >= 0)
                    ans += mat[r1 - 1][c1 - 1];
                result[i][j] = ans;
            }
        return result;
    }
};