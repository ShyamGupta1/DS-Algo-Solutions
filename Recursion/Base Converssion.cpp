#include <bits/stdc++.h>
using namespace std;

void printFib(long n)
{
    if (n == 0)
        return;
    printFib(n / 2);
    cout << n % 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;
        printFib(n);
        cout << endl;
    }
    return 0;
}