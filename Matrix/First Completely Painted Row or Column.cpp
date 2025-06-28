// T.C : O(n)
// S.C : O(n^2)

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {

        int m = mat.size(), n = mat[0].size();
        // key val -> col
        map<int, int> row;
        // key val -> row
        map<int, int> col;

        map<int, int> eachRow;
        map<int, int> eachCol;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                row[mat[i][j]] = i, col[mat[i][j]] = j;
        for (int i = 0; i < arr.size(); i++)
        {
            int r = row[arr[i]], c = col[arr[i]];
            eachRow[r]++, eachCol[c]++;
            if (eachRow[r] == n or eachCol[c] == m)
                return i;
        }
        return 0;
    }
};