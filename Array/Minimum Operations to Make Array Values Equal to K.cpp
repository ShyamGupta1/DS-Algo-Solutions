// T.C : O(N)
// S.C :O(N)

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {

        set<int> mp(nums.begin(), nums.end());

        int count = 0;
        auto tt = mp.begin();
        if (*tt < k)
            return -1;
        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            if (*it == k)
                break;
            count++;
        }
        return count;
    }
};

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {

        set<int> st(nums.begin(), nums.end());
        int count = 0;
        for (auto x : st)
        {
            if (x > k)
                count++;
            if (x < k)
                return -1;
        }
        return count;
    }
};
