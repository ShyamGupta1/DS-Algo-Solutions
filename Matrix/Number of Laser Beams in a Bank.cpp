// T.C : O(M*N)
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {

        vector<int> ans;
        for (int i = 0; i < bank.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < bank[i].size(); j++)
                if (bank[i][j] == '1')
                    count++;
            if (count)
                ans.push_back(count);
        }
        if (ans.size() <= 1)
            return 0;
        int total = 0;
        for (int i = 0; i < ans.size() - 1; i++)
            total += (ans[i] * ans[i + 1]);
        return total;
    }
};