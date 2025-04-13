// T.C: O(N∗M∗Log(M))  M-> Length of each String, N -> Total String
// S.C: O(M*N)

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        vector<string> copy = strs;
        for (string &s : copy)
            sort(s.begin(), s.end());
        map<string, vector<string>> mp;
        for (int i = 0; i < copy.size(); i++)
            mp[copy[i]].push_back(strs[i]);
        vector<vector<string>> result;
        for (auto x : mp)
            result.push_back(x.second);
        return result;
    }
};

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        map<string, vector<string>> mp;
        for (string s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        vector<vector<string>> result;
        for (auto x : mp)
            result.push_back(x.second);
        return result;
    }
};