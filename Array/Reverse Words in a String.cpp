// T.C : O(N)
// S.C : O(1)

class Solution
{
public:
    string reverseWords(string s)
    {
        string ans;
        int n = s.size();
        int i = n - 1, j = n - 1;
        while (i >= 0 and s[i] == ' ')
            i--;
        j = i;
        int num = 2;
        while (i >= 0)
        {
            while (i >= 0 and s[i] != ' ')
                i--;
            ans.insert(ans.end(), s.begin() + i + 1, s.begin() + j + 1);
            ans += " ";
            while (i >= 0 and s[i] == ' ')
                i--;
            j = i;
        }
        ans.erase(ans.end() - 1);
        return ans;
    }
};