// T.C: O(nlogn)
// S.C: O(1)

class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {

        int count = 0, n = arr.size();
        int left = 0, right = n - 1;
        sort(arr.begin(), arr.end());
        while (left < right)
        {
            int sum = arr[left] + arr[right];
            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
            {
                if (arr[left] == arr[right])
                    count += (((right - left + 1) * (right - left)) / 2);
                else
                {
                    int leftFreq = 1, rightFreq = 1;
                    while (arr[left + 1] == arr[left])
                        leftFreq++, left++;
                    while (arr[right - 1] == arr[right])
                        rightFreq++, right--;
                    count += (leftFreq * rightFreq);
                }
                left++, right--;
            }
        }
        return count;
    }
};