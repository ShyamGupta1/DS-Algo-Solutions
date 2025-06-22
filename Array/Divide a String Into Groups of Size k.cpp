// T.C : O(N)
// S.C : O(1)

class Solution
{
public:
    vector<string> divideString(string s, int k, char fill)
    {

        int i = 0, j = k;
        vector<string> ans;

        for (; i <= s.size() - k and j <= s.size(); i += k, j += k)
        {
            string temp;
            temp.insert(temp.begin(), s.begin() + i, s.begin() + j);
            ans.push_back(temp);
        }
        if (s.size() % k)
        {
            string temp;
            i = (s.size() / k) * k, j = s.size() % k;
            while (i < s.size())
                temp.push_back(s[i]), i++;
            while (j < k)
                temp.push_back(fill), j++;
            ans.push_back(temp);
        }
        return ans;
    }
};