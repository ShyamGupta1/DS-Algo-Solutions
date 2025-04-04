// T.C : O(n)
// S.C: O(1)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int left = 0, right = n - 1, count = 0, mod = 1e9 + 7;
    while (left <= right)
    {
        int area = arr[left] * arr[right];
        if (area >= target)
            right--;
        else
        {
            count = count % mod + (2 * (right - left + 1) - 1) % mod;
            left++;
        }
    }
    cout << count % mod;
    return 0;
}