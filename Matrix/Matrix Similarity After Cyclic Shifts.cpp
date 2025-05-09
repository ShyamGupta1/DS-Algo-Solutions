class Solution
{
public:
    void leftShift(vector<int> &arr, int s)
    {
        while (s--)
        {
            int temp = arr[0];
            for (int i = 0; i < arr.size() - 1; i++)
                arr[i] = arr[i + 1];
            arr[arr.size() - 1] = temp;
        }
    }
    void rightShift(vector<int> &arr, int s)
    {
        while (s--)
        {
            int temp = arr[arr.size() - 1];
            for (int i = arr.size() - 1; i >= 1; i--)
                arr[i] = arr[i - 1];
            arr[0] = temp;
        }
    }
    bool areSimilar(vector<vector<int>> &mat, int k)
    {

        vector<vector<int>> copy = mat;
        int m = mat.size(), n = mat[0].size();
        int rot = k % n;
        for (int i = 0; i < m; i++)
        {
            if (i & 1)
                rightShift(mat[i], rot);
            else
                leftShift(mat[i], rot);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (copy[i][j] != mat[i][j])
                    return false;
        return true;
    }
};