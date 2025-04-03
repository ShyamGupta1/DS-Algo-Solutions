#include <bits/stdc++.h>
using namespace std;

void printFib(long n)
{
    if (n == 0)
        return;
    printFib(n / 10);
    cout << n % 10 << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;
        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        printFib(n);
        cout << endl;
    }
    return 0;
}