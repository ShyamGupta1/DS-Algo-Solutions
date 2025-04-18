// T.C: O(N*N)

class Solution
{
public:
    vector<vector<int>> makePair(string s)
    {
        vector<vector<int>> ans;
        int i = 0;
        while (i < s.size())
        {
            int digit = s[i] - '0', count = 1;
            while (s[i] == s[i + 1])
                count++, i++;
            ans.push_back({digit, count});
            i++;
        }
        return ans;
    }
    string makeInteger(vector<vector<int>> pairs)
    {
        string s;
        for (auto x : pairs)
            s += (to_string(x[1]) + to_string(x[0]));
        return s;
    }
    string getSol(int n)
    {
        if (n == 1)
            return "1";
        return makeInteger(makePair(getSol(n - 1)));
    }
    string countAndSay(int n)
    {
        return getSol(n);
    }
};