#include <bits/stdc++.h>
using namespace std;

int fact = 1;
void printFib(int n)
{
    if (n == 0)
        return;
    fact *= n;
    printFib(n - 1);
}

int main()
{
    int n;
    cin >> n;
    printFib(n);
    cout << fact;
    return 0;
}