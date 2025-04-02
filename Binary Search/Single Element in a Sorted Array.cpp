// Approach 1: (Bit Manipulation) T.C: O(N)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int num = 0;
        for (int i = 0; i < nums.size(); i++)
            num ^= nums[i];
        return num;
    }
};

// Approach 2: (Binary Search) T.C: O(logN)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;
        int n = nums.size();
        if (n == 1)
            return nums[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (mid == 0 and nums[mid] != nums[mid + 1])
                return nums[mid];
            if (mid == n - 1 and nums[mid] != nums[mid - 1])
                return nums[mid];

            if (nums[mid - 1] != nums[mid] and nums[mid + 1] != nums[mid])
                return nums[mid];

            if (mid % 2 and nums[mid] == nums[mid - 1])
                low = mid + 1;
            else if (mid % 2 == 0 and nums[mid] == nums[mid + 1])
                low = mid + 1;
            if (mid % 2 and nums[mid] != nums[mid - 1])
                high = mid - 1;
            else if (mid % 2 == 0 and nums[mid] != nums[mid + 1])
                high = mid - 1;
        }
        return 0;
    }
};