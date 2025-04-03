// Approach 1: (Brute Force)
// T.C : O(n^2)
// S.C : O(1)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target)
                    return {i, j};
        return nums;
    }
};

// Approach 2: (Two Pointer)
// T.C : O(nlogn)
// S.C : O(n)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        int n = nums.size();
        vector<int> copy = nums;
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == target)
                break;
            if (sum > target)
                right--;
            else
                left++;
        }
        int first = -1, second = -1;
        vector<int>::iterator it1, it2;
        if (nums[left] == nums[right])
        {
            it1 = find(copy.begin(), copy.end(), nums[left]);
            it2 = find(it1 + 1, copy.end(), nums[right]);
        }
        else
        {
            it1 = find(copy.begin(), copy.end(), nums[left]);
            it2 = find(copy.begin(), copy.end(), nums[right]);
        }
        first = it1 - copy.begin();
        second = it2 - copy.begin();

        return {first, second};
    }
};

// Approach 3: (Binary Search)
// T.C : O(nlogn)
// S.C : O(n)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        int n = nums.size();
        vector<int> copy = nums;
        sort(nums.begin(), nums.end());
        int first = -1, second = -1;
        for (int i = 0; i < n - 1; i++)
        {
            int toFind = target - nums[i];
            int low = i + 1, high = n - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid] == toFind)
                {
                    first = i, second = mid;
                    break;
                }
                if (nums[mid] < toFind)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        vector<int>::iterator it1, it2;
        if (nums[first] == nums[second])
        {
            it1 = find(copy.begin(), copy.end(), nums[first]);
            it2 = find(it1 + 1, copy.end(), nums[second]);
        }
        else
        {
            it1 = find(copy.begin(), copy.end(), nums[first]);
            it2 = find(copy.begin(), copy.end(), nums[second]);
        }
        first = it1 - copy.begin();
        second = it2 - copy.begin();

        return {first, second};
    }
};

// Approach 4: (Hash Map)
// T.C : O(n)
// S.C : O(n)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++)
            if (mp.find(target - nums[i]) != mp.end() and i != mp[target - nums[i]])
                return {i, mp[target - nums[i]]};
        return {-1, -1};
    }
};
