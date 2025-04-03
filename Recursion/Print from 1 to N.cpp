#include <bits/stdc++.h>
using namespace std;

void printFib(int n)
{
    if (n == 0)
        return;
    printFib(n - 1);
    cout << n << endl;
}

int main()
{
    int n;
    cin >> n;
    printFib(n);
    return 0;
}