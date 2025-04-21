// T.C : O(m *n)
// S.C : O(1) (no extra space depends on input size)

/*
map<int,int> mp → At most 8 keys (3 rows + 3 cols + 2 diagonals), so constant -> O(1)

set<int> st → At most 9 digits (1 to 9), so constant -> O(1)

string s → length 9 at max → O(1)
*/

class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {

        int m = grid.size(), n = grid[0].size();
        if (m * n < 9)
            return 0;
        int count = 0;
        // Traverse over all 3X3 subMatrix
        for (int i = 1; i < m - 1; i++)
            for (int j = 1; j < n - 1; j++)
            {
                int r1 = i - 1, c1 = j - 1, r2 = i + 1, c2 = j + 1;
                map<int, int> mp;
                set<int> st;
                string s;
                int sum, totalSum = 0;
                // Traverse over all rows and calculate sum of each row
                for (int p = r1; p <= r2; p++)
                {
                    sum = 0;
                    for (int q = c1; q <= c2; q++)
                        sum += grid[p][q], st.insert(grid[p][q]), s += (to_string(grid[p][q])), totalSum += grid[p][q];
                    mp[sum]++;
                }
                if (s.size() != 9 or st.size() != 9 or totalSum != 45)
                    continue;

                // Traverse over all cols and calculate sum of each row
                for (int q = c1; q <= c2; q++)
                {
                    sum = 0;
                    for (int p = r1; p <= r2; p++)
                        sum += grid[p][q];
                    mp[sum]++;
                }

                // Diagonal sum
                sum = grid[i][j] + grid[r1][c1] + grid[r2][c2];
                mp[sum]++;
                sum = grid[i][j] + grid[r1][c2] + grid[r2][c1];
                mp[sum]++;
                if (mp.size() == 1 and mp.begin()->second == 8)
                    count++;
            }
        return count;
    }
};