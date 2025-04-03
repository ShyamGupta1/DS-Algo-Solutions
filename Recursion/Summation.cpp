#include <bits/stdc++.h>
using namespace std;

long long sum;
void printFib(vector<int> arr, int n)
{
    if (n < 0)
        return;
    sum += arr[n];
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
    cout << sum;
    return 0;
}