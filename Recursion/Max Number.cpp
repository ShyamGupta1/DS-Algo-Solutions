#include <bits/stdc++.h>
using namespace std;

int maxi = INT_MIN;
void printFib(vector<int> arr, int n)
{
    if (n < 0)
        return;
    maxi = max(arr[n], maxi);
    printFib(arr, n - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    printFib(nums, n - 1);
    cout << maxi;
    return 0;
}