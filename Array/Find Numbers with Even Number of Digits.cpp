// T.C : O(N)
// S.C : O(1)

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {

        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int digits = log10(nums[i]) + 1;
            if (!(digits & 1))
                count++;
        }
        return count;
    }
};