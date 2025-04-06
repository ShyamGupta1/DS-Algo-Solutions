// T.C : O(N)
// S.C : (1) (Excluding output)

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {

        int xo = 0;
        vector<int> ans;
        ans.push_back(pref[0]);
        for (int i = 1; i < pref.size(); i++)
        {
            xo = pref[i] ^ pref[i - 1];
            ans.push_back(xo);
        }
        return ans;
    }
};