// T.C : O(N^2)
// S.C : O(N)

class Solution
{
public:
    int dis(int x1, int y1, int x2, int y2)
    {
        int a = abs(x1 - x2);
        int b = abs(y1 - y2);
        return ((a * a) + (b * b));
    }
    int numberOfBoomerangs(vector<vector<int>> &points)
    {

        int ans = 0;
        for (int i = 0; i < points.size(); i++)
        {
            map<int, int> mp;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                    continue;
                int length = dis(points[i][0], points[i][1], points[j][0], points[j][1]);
                mp[length]++;
            }

            for (auto x : mp)
                if (x.second > 1)
                    ans += x.second * (x.second - 1);
        }

        return ans;
    }
};