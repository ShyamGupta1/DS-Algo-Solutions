#include <bits/stdc++.h>
using namespace std;

void printFib(int arr[], int i, int n)
{

    i += 2;
    if (i >= n)
        return;
    printFib(arr, i, n);
    cout << arr[i] << " ";
}

int main()
{
    int t;
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++)
        cin >> arr[i];
    printFib(arr, -2, t);

    return 0;
}