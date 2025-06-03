// T.C : O(N^2)
// S.C : O(1)

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int max = 0;
        for (auto x : accounts)
            max = std::max(accumulate(x.begin(), x.end(), 0), max);
        return max;
    }
};