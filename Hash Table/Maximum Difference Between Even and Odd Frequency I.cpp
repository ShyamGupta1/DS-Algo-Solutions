// T.C : O(N)
// S.C : O(1)

class Solution
{
public:
    int maxDifference(string s)
    {
        map<char, int> mp;
        for (auto ch : s)
            mp[ch]++;
        int evenMAX = 0, evenMIN = INT_MAX, oddMAX = 0, oddMIN = INT_MAX;
        for (auto x : mp)
        {
            if (x.second & 1)
            {
                if (x.second > oddMAX)
                    oddMAX = x.second;
                if (x.second < oddMIN)
                    oddMIN = x.second;
            }
            else
            {
                if (x.second > evenMAX)
                    evenMAX = x.second;
                if (x.second < evenMIN)
                    evenMIN = x.second;
            }
        }
        // find MAX Diff
        int diff1 = -evenMAX + oddMIN;
        int diff2 = oddMAX - evenMIN;
        return diff1 > diff2 ? diff1 : diff2;
    }
};