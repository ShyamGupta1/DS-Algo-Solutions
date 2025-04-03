#include <bits/stdc++.h>
using namespace std;

void printFib(int n)
{
    if (n == 1)
    {
        cout << n;
        return;
    }
    cout << n << " ";
    printFib(n - 1);
}

int main()
{
    int n;
    cin >> n;
    printFib(n);
    return 0;
}