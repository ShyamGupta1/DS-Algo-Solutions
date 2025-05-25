// T.C : O(N*L) where N is the number of words and L is the average length of the words.

class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {

        vector<int> ans;
        int k = 0;
        for (auto s : words)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (x == s[i])
                {
                    ans.push_back(k);
                    break;
                }
            }
            k++;
        }
        return ans;
    }
};