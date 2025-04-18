// T.C: O(LogN)
// S.C: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1, high = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid))
            {
                if (mid == 1)
                    return 1;
                if (!isBadVersion(mid - 1))
                    return mid;
            }
            if (isBadVersion(mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return 0;
    }
};