// T.C: O(N)
// S.C: O(1) Excluding output string

class Solution
{
public:
    string largestOddNumber(string num)
    {

        string ans;
        int n = num.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int odd = num[i] - '0';
            if (odd % 2)
            {
                ans.insert(ans.end(), num.begin(), num.begin() + i + 1);
                break;
            }
        }
        return ans;
    }
};