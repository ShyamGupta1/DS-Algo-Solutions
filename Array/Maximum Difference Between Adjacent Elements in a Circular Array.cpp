// T.C : O(N)
// S.C : O(1)

class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int n = nums.size(), max = abs(nums[0] - nums[n - 1]);
        for (int i = 0; i < nums.size() - 1; i++)
            max = std::max(max, abs(nums[i] - nums[i + 1]));
        return max;
    }
};