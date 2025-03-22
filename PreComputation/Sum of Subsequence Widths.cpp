// T.C : O(NlogN)
// S.C : O(1)

class Solution
{
public:
    int sumSubseqWidths(vector<int> &nums)
    {
        long long ans = 0, mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (long i = 0, powe = 1; i < nums.size(); i++, powe = (2 * powe) % mod)
            ans = (ans + powe * (nums[i] % mod - nums[n - i - 1] % mod)) % mod;
        return ans;
    }
};