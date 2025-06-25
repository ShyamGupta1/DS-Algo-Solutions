// T.C: O(N^2)
// S.C: O(N)

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {

        vector<int> idx;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == key)
                idx.push_back(i);
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < idx.size(); j++)
            {
                if (abs(i - idx[j]) <= k)
                {
                    ans.push_back(i);
                    break;
                }
            }
        return ans;
    }
};