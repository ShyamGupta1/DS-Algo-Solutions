// T.C : O(N^2)
// S.C : O(1)

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {

        int n = mat.size();
        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (mat[i][j] != target[i][j])
                    flag = true;
            if (flag)
                break;
        }
        if (flag == false)
            return true;

        // First Rotate
        flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (mat[i][j] != target[j][n - i - 1])
                    flag = true;
            if (flag)
                break;
        }
        if (flag == false)
            return true;

        // Second Rotate
        flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (mat[i][j] != target[n - i - 1][n - j - 1])
                    flag = true;
            if (flag)
                break;
        }
        if (flag == false)
            return true;

        // Third Rotation
        flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (mat[i][j] != target[n - j - 1][n - i - 1])
                    flag = true;
            if (flag)
                break;
        }
        if (flag == false)
            return true;

        // Fourth Rotation
        flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (mat[i][j] != target[n - j - 1][i])
                    flag = true;
            if (flag)
                break;
        }
        if (flag == false)
            return true;

        return false;
    }
};

// T.C : O(N^2)
// S.C : O(1)

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {

        int n = mat.size();
        bool flag = false;
        int rot = 4;
        while (rot--)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    if (mat[i][j] != target[i][j])
                        flag = true;
                if (flag)
                    break;
            }
            if (!flag)
                return true;
            else
                flag = false;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i < j)
                        swap(mat[i][j], mat[j][i]);
            for (auto &x : mat)
                reverse(x.begin(), x.end());
        }
        return false;
    }
};