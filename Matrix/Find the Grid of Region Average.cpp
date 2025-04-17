// T.C : O(M*N)
// S.C : O(M*N)

class Solution
{
public:
    vector<vector<int>> resultGrid(vector<vector<int>> &image, int threshold)
    {

        int m = image.size(), n = image[0].size();
        vector<vector<int>> totalRegions(m, vector<int>(n, 0));
        vector<vector<int>> averageSum(m, vector<int>(n, 0));
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                // First Check wheather it is a valid region or not
                int r1 = i - 1, r2 = i + 1, c1 = j - 1, c2 = j + 1;

                // Check all adjacent pixels in rows first
                bool found1 = false;
                for (int p = r1; p <= r2; p++)
                {
                    for (int q = c1; q < c2; q++)
                        if (abs(image[p][q] - image[p][q + 1]) > threshold)
                            found1 = true;
                    if (found1)
                        break;
                }
                // Check all adjacent pixels in col
                bool found2 = false;

                for (int p = r1; p < r2; p++)
                {
                    for (int q = c1; q <= c2; q++)
                        if (abs(image[p][q] - image[p + 1][q]) > threshold)
                            found2 = true;
                    if (found2)
                        break;
                }
                if (!found1 and !found2)
                {
                    // find average
                    int sum = 0;
                    for (int p = r1; p <= r2; p++)
                        for (int q = c1; q <= c2; q++)
                            sum += image[p][q];
                    int avg = sum / 9;
                    for (int p = r1; p <= r2; p++)
                        for (int q = c1; q <= c2; q++)
                            averageSum[p][q] += avg, totalRegions[p][q]++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << averageSum[i][j] << " ";

                if (!totalRegions[i][j])
                    averageSum[i][j] = image[i][j];
                else
                    averageSum[i][j] /= totalRegions[i][j];
            }
            cout << endl;
        }
        return averageSum;
    }
};