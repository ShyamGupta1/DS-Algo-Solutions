#include <bits/stdc++.h>
using namespace std;

void printFib(int n)
{
    if (n == 0)
        return;
    cout << "I love Recursion\n";
    printFib(n - 1);
}

int main()
{
    int n;
    cin >> n;
    printFib(n);
    return 0;
}